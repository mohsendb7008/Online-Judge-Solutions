#include <vector>
#include <algorithm>

/**
 * Eulerian Graph
 *
 * Authors:
 * - Mohsen Dehbashi
 * - Ghazal Rabiei
 */

class Node {
    size_t _index;

public:
    explicit Node(const size_t index) : _index(index){
    }

    size_t getIndex() const {
        return _index;
    }
};

template<typename T = int>
class Edge {
    Node _source;
    Node _destination;
    T _tag;

public:
    explicit Edge(const Node source, const Node destination, const T tag) :
        _source(source), _destination(destination), _tag(tag) {
    }

    Node getSource() const {
        return _source;
    }

    Node getDestination() const {
        return _destination;
    }

    T getTag() const {
        return _tag;
    }
};

template <typename T = int>
class EulerGraph {
    std::vector<std::vector<Edge<T>>> _adjacents;
    std::vector<size_t> _indegree, _outdegree;
    std::vector<Node> _eulerNodes;
    std::vector<Edge<T>> _eulerEdges;

    void dfs(const size_t u) {
        while (!_adjacents[u].empty()) {
            const Edge<T> e = *_adjacents[u].rbegin();
            _adjacents[u].pop_back();
            dfs(e.getDestination().getIndex());
            _eulerEdges.push_back(e);
        }
        _eulerNodes.emplace_back(u);
    }

public:
    explicit EulerGraph(const size_t size) {
        _adjacents.assign(size, std::vector<Edge<T>>());
        _indegree.assign(size, 0);
        _outdegree.assign(size, 0);
    }

    void addEdge(const Edge<T> &edge) {
        _adjacents[edge.getSource().getIndex()].push_back(edge);
        ++_indegree[edge.getDestination().getIndex()];
        ++_outdegree[edge.getSource().getIndex()];
    }

    /**
     * Time Complexity: O(V + E)
     * Space Complexity: O(V + E)
     */
    bool isEulerian() {
        size_t eulerStartIndex = 0;
        std::vector<size_t> odds;
        for (size_t i = 0; i < _adjacents.size(); i++) {
            if (_indegree[i] != _outdegree[i]) {
                odds.push_back(i);
            }
        }
        if (odds.size() == 1 || odds.size() > 2)
            return false;
        if (odds.empty()) {
            for (size_t i = 0; i < _adjacents.size(); i++) {
                if (!_adjacents[i].empty()) {
                    eulerStartIndex = i;
                    break;
                }
            }
        }
        else {
            const size_t u = odds[0], v = odds[1];
            if ((_indegree[u] - _outdegree[u]) * (_indegree[v] - _outdegree[v]) != -1)
                return false;
            if (_outdegree[u] > _indegree[u]) {
                eulerStartIndex = u;
            }
            else {
                eulerStartIndex = v;
            }
        }
        dfs(eulerStartIndex);
        for (size_t i = 0; i < _adjacents.size(); i++) {
            if (!_adjacents[i].empty()) {
                return false;
            }
        }
        std::reverse(_eulerNodes.begin(), _eulerNodes.end());
        std::reverse(_eulerEdges.begin(), _eulerEdges.end());
        return true;
    }

    /**
     * isEulerian() should be called before calling this method.
     */
    std::vector<Node> getEulerianNodes() {
        return _eulerNodes;
    }

    /**
     * isEulerian() should be called before calling this method.
     */
    std::vector<Edge<T>> getEulerianEdges() {
        return _eulerEdges;
    }
};