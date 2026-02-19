#include <vector>
#include <queue>
#include <algorithm>

/**
 * Graph V1:
 * - Adjacency List
 * - Dijkstra
 *
 * Authors:
 * - Mohsen Dehbashi
 * - Ghazal Rabiei
 */

class Node {
    size_t _index;

public:
    explicit Node(const size_t index) : _index(index) {
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
    explicit Edge(const Node source, const Node destination, const T weight) : _source(source),
                                                                               _destination(destination),
                                                                               _weight(weight) {
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
 * Represents a state in the min-priority queue.
 * Reversed comparison to simulate min-heap behavior.
 */
template<typename T>
class DijkstraState {
    Node _target;
    T _distance;

public:
    explicit DijkstraState(const Node target, const T distance) : _target(target), _distance(distance) {
    }

    Node getTarget() const {
        return _target;
    }

    T getDistance() const {
        return _distance;
    }

    bool operator <(const DijkstraState &other) const {
        return !(_distance < other.getDistance());
    }
};

/**
 * Stores shortest distances and path reconstruction data.
 * _trace[i] = predecessor of node i
 */
template<typename T>
class DijkstraResult {
    std::vector<T> _minDistance;
    std::vector<size_t> _trace;

public:
    explicit DijkstraResult(const size_t size, T maxValue = std::numeric_limits<T>::max()) {
        _minDistance.assign(size, maxValue); // Max value = unreachable
        _trace.assign(size, size); // Size value = no predecessor
    }

    T getMinDistance(const Node &target) const {
        return _minDistance[target.getIndex()];
    }

    std::vector<size_t> getMinPath(const Node &target) const {
        std::vector<size_t> path;
        size_t iterator = target.getIndex();
        if (_trace[iterator] == _trace.size())
            return path;
        while (iterator != _trace.size()) {
            path.push_back(iterator);
            iterator = _trace[iterator];
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    bool updateMinDistance(const Node &target, const T candidateDistance, const size_t originIndex) {
        if (candidateDistance < _minDistance[target.getIndex()]) {
            _minDistance[target.getIndex()] = candidateDistance;
            _trace[target.getIndex()] = originIndex;
            return true;
        }
        return false;
    }
};

/**
 * Directed weighted graph using adjacency list.
 */
template<typename T>
class GraphV1 {
    std::vector<std::vector<Edge<T> > > _adjacents;

public:
    explicit GraphV1(const size_t size) {
        _adjacents.assign(size, std::vector<Edge<T> >());
    }

    void addEdge(const Edge<T> &edge) {
        _adjacents[edge.getSource().getIndex()].push_back(edge);
    }

    void addBidirectionalEdge(const Edge<T> &edge) {
        _adjacents[edge.getSource().getIndex()].push_back(edge);
        addEdge(Edge<T>(edge.getDestination(), edge.getSource(), edge.getWeight()));
    }

    /**
     * Time Complexity: O((V + E) log V)
     * Space Complexity: O(V + E)
     */
    DijkstraResult<T> dijkstra(const Node &source, T initialDistance, T maxValue = std::numeric_limits<T>::max()) {
        DijkstraResult<T> result(_adjacents.size(), maxValue);
        std::priority_queue<DijkstraState<T> > queue;

        result.updateMinDistance(source, initialDistance, _adjacents.size());
        DijkstraState<T> sourceState(source, initialDistance);
        queue.push(sourceState);

        while (!queue.empty()) {
            DijkstraState<T> state = queue.top();
            queue.pop();

            const Node &target = state.getTarget();
            const T &distance = state.getDistance();

            if (result.getMinDistance(target) < distance)
                continue;

            for (const Edge<T> &edge: _adjacents[target.getIndex()]) {
                const Node &neighbor = edge.getDestination();
                const T &weight = edge.getWeight();

                if (result.updateMinDistance(neighbor, result.getMinDistance(target) + weight,
                                             target.getIndex())) {
                    DijkstraState<T> neighborState(neighbor, result.getMinDistance(neighbor));
                    queue.push(neighborState);
                }
            }
        }
        return result;
    }

    T prim(const Node &source, T initial) {
        std::priority_queue<std::pair<T, size_t>, std::vector<std::pair<T, size_t>>, std::greater<>> pq;
        std::vector<bool> taken(_adjacents.size(), false);
        auto process = [this, &pq, &taken](const size_t u) -> void {
            taken[u] = true;
            for (const Edge<T> &edge: _adjacents[u]) {
                const Node &neighbor = edge.getDestination();
                if (taken[neighbor.getIndex()])
                    continue;
                const T &weight = edge.getWeight();
                pq.emplace(weight, neighbor.getIndex());
            }
        };
        process(source.getIndex());
        T sum = initial;
        while (!pq.empty()) {
            auto state = pq.top();
            pq.pop();
            if (taken[state.second])
                continue;
            sum += state.first;
            process(state.second);
        }
        return sum;
    }
};