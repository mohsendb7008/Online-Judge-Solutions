#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

/**
 * Graph V1:
 * - Adjacency List
 * - SSSP Dijkstra (+Time Table)
 * - MST Prim
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
    // Timetable properties implying that the edge is only usable at time (k * _p + _t0) for all non-negative integers k:
    T _t0; // timetable initial value (default = 0)
    T _p; // timetable periodicity (default = 1)

public:
    explicit Edge(const Node source, const Node destination, const T weight) :
        _source(source), _destination(destination), _weight(weight), _t0(0), _p(1) {
    }

    explicit Edge(const Node source, const Node destination, const T weight, const T t0, const T p) :
        _source(source), _destination(destination), _weight(weight), _t0(t0), _p(p) {
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

    T getT0() const {
        return _t0;
    }

    T getP() const {
        return _p;
    }

    bool operator <(const Edge &other) const {
        return !(_weight < other.getWeight()); // reverse logic to work easier with std::priority_queue
    }

    /**
     * @param weight Current time
     * @param maxValue Infinity
     * @return Next available time according to timetable properties
     */
    T ceiling(T weight, T maxValue) const {
        if (weight <= _t0) {
            return  _t0;
        }
        if (_p == 0) {
            return maxValue;
        }
        const T diff = weight - _t0;
        const T t = diff / _p + (diff % _p ? 1 : 0);
        return _t0 + t * _p;
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
        return !(_distance < other.getDistance()); // reverse logic to work easier with std::priority_queue
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
    std::vector<std::vector<Edge<T>>> _adjacents;

public:
    explicit GraphV1(const size_t size) {
        _adjacents.assign(size, std::vector<Edge<T>>());
    }

    void addEdge(const Edge<T> &edge) {
        _adjacents[edge.getSource().getIndex()].push_back(edge);
    }

    void addBidirectionalEdge(const Edge<T> &edge) {
        _adjacents[edge.getSource().getIndex()].push_back(edge);
        addEdge(Edge<T>(edge.getDestination(), edge.getSource(),
            edge.getWeight(), edge.getT0(), edge.getP()));
    }

    /**
     * Single Source Shortest Path
     * Time Complexity: O((V + E) log V)
     * Space Complexity: O(V + E)
     */
    DijkstraResult<T> dijkstra(const Node &source, T initialDistance, T maxValue = std::numeric_limits<T>::max(),
            const size_t stopIndex = std::numeric_limits<size_t>::max()) {
        DijkstraResult<T> result(_adjacents.size(), maxValue);
        std::priority_queue<DijkstraState<T>> queue;
        // Initial with source node:
        result.updateMinDistance(source, initialDistance, _adjacents.size());
        DijkstraState<T> sourceState(source, initialDistance);
        queue.push(sourceState);
        // Iterate greedily:
        while (!queue.empty()) {
            DijkstraState<T> state = queue.top();
            queue.pop();
            const Node &target = state.getTarget();
            const T &distance = state.getDistance();
            // Early termination if destination is static:
            if (target.getIndex() == stopIndex)
                break;
            // Drop invalid state:
            if (result.getMinDistance(target) < distance)
                continue;
            // Process target neighbors:
            for (const Edge<T> &edge: _adjacents[target.getIndex()]) {
                const Node &neighbor = edge.getDestination();
                const T &weight = edge.getWeight();
                T candidateDistance = result.getMinDistance(target);
                if (std::is_arithmetic<T>()) { // Only apply timetable if T is arithmetic
                    candidateDistance = edge.ceiling(candidateDistance, maxValue);
                    if (candidateDistance == maxValue) {
                        continue;
                    }
                }
                if (result.updateMinDistance(neighbor, candidateDistance + weight, target.getIndex())) {
                    DijkstraState<T> neighborState(neighbor, result.getMinDistance(neighbor));
                    queue.push(neighborState);
                }
            }
        }
        return result;
    }

    /**
     * Minimum Spanning Tree
     * Time Complexity: O((V + E) log V)
     * Space Complexity: O(V + E)
     */
    std::vector<Edge<T>> prim(const Node &source) {
        std::priority_queue<Edge<T>> queue;
        std::vector<bool> taken(_adjacents.size(), false);
        // Process neighbors lambda:
        auto process = [this, &queue, &taken](const size_t u) -> void {
            taken[u] = true;
            for (const Edge<T> &edge: _adjacents[u]) {
                if (taken[edge.getDestination().getIndex()])
                    continue;
                queue.push(edge);
            }
        };
        // Initiate with source node:
        std::vector<Edge<T>> result;
        process(source.getIndex());
        // Iterate greedily:
        while (!queue.empty()) {
            Edge<T> edge = queue.top();
            queue.pop();
            if (taken[edge.getDestination().getIndex()])
                continue;
            result.push_back(edge);
            process(edge.getDestination().getIndex());
        }
        return result;
    }
};