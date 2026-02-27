#include <vector>
#include <algorithm>

/**
 * Graph V2:
 * - Edge List
 * - Bellman Ford
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

template<typename T>
class Edge {
    Node _source;
    Node _destination;
    T _weight;

public:
    explicit Edge(const Node source, const Node destination, const T weight) :
        _source(source), _destination(destination), _weight(weight) {
    }

    Node getSource() const {
        return _source;
    }

    Node getDestination() const {
        return _destination;
    }

    T getWeight() const {
        return _weight;
    }
};

/**
 * Directed weighted graph using edge list.
 */
template<typename T>
class GraphV2 {
    std::vector<Edge<T>> _edges;
    std::vector<T> _distance;
    std::vector<size_t> _parent;
    T _minValue; // -inf (for negative cycles)
    T _maxValue; // inf

public:
    explicit GraphV2(const size_t size, T minValue, T maxValue): _minValue(minValue), _maxValue(maxValue) {
        _distance.assign(size, maxValue); // maxValue = unreachable
        _parent.assign(size, size); // size = no predecessor
    }

    void addEdge(const Edge<T> &edge) {
        _edges.push_back(edge);
    }

    /**
     * Single Source Shortest Path with Negative Cycles
     * Time Complexity: O(V * E)
     * Space Complexity: O(V + E)
     */
    void bellmanFord(const Node &source, T initialValue) {
        // Initiate source node:
        _distance.assign(_distance.size(), _maxValue);
        _distance[source.getIndex()] = initialValue;
        // Iterate V-1 times for shortest paths, V-1 times to detect negative cycles
        for (size_t i = 0; i < 2 * (_distance.size() - 1); i++) {
            for (const Edge<T> &edge: _edges) {
                // There is an edge from u -> v with weight w
                size_t u = edge.getSource().getIndex();
                size_t v = edge.getDestination().getIndex();
                const T &weight = edge.getWeight();
                if (_distance[u] < _maxValue && _distance[u] + weight < _distance[v]) {
                    if (i >= _distance.size()) {
                        _distance[v] = _minValue; // v is inside a negative cycle
                    } else {
                        _distance[v] = _distance[u] + weight;
                        _parent[v] = u;
                    }
                }
            }
        }
    }

    T getMinDistance(const Node &target) {
        return _distance[target.getIndex()];
    }

    std::vector<size_t> getMinPath(const Node& source, const Node& target) {
        std::vector<size_t> path;
        if (_distance[target.getIndex()] == _maxValue) // unreachable
            return path;
        size_t iterator = target.getIndex();
        while (iterator != source.getIndex()) {
            path.push_back(iterator);
            iterator = _parent[iterator];
        }
        path.push_back(source.getIndex());
        std::reverse(path.begin(), path.end());
        return path;
    }
};