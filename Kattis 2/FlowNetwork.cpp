#include <vector>
#include <queue>
#include <set>
#include <algorithm>

/**
 * Flow Network:
 * - Edmond Karp (Max Flow)
 * - Johnson Potentials (Min Cost Max Flow)
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

template <typename TF = int, typename TW = long>
class FlowNetwork {
    std::vector<std::set<size_t>> _adjacents;
    std::vector<std::vector<TF>> _capacity;
    std::vector<std::vector<TF>> _flow;
    std::vector<std::vector<TW>> _cost;

    /**
     * Used by max flow.
     * Finds some path from source to sink in residual graph.
     */
    std::vector<size_t> getPathBfs(const Node& source, const Node& sink) {
        std::vector<size_t> trace(_adjacents.size(), _adjacents.size()); // _adjacents.size() = no predecessor
        std::queue<size_t> bfs;
        // Initiate with source node:
        trace[source.getIndex()] = source.getIndex();
        bfs.push(source.getIndex());
        // Iterate level by level:
        while (!bfs.empty()) {
            const size_t u = bfs.front();
            bfs.pop();
            // Early termination since destination is always sink:
            if (u == sink.getIndex())
                break;
            // Process neighbors:
            for (const size_t v : _adjacents[u]) {
                if (trace[v] == _adjacents.size()) { // v is not visited
                    TF residual = _capacity[u][v] - _flow[u][v];
                    if (residual > 0) { // There are some flow available from u -> v
                        trace[v] = u;
                        bfs.push(v);
                    }
                }
            }
        }
        std::vector<size_t> path;
        if (trace[sink.getIndex()] == _adjacents.size()) // Network is full
            return path;
        // Build flow path:
        size_t iterator = sink.getIndex();
        while (trace[iterator] != iterator) {
            path.push_back(iterator);
            iterator = trace[iterator];
        }
        path.push_back(source.getIndex());
        std::reverse(path.begin(), path.end());
        return path;
    }

    /**
     * Used by max flow.
     * If a path exists from source to sink in residual graph, calculates flow bottleneck and applies.
     */
    TF tryAugment(const Node& source, const Node& sink) {
        const std::vector<size_t> &path = getPathBfs(source, sink);
        if (path.empty())
            return 0;
        // Calculate flow bottleneck:
        TF flow = std::numeric_limits<TF>::max();
        for (size_t i = 1; i < path.size(); i++) {
            TF residual = _capacity[path[i-1]][path[i]] - _flow[path[i-1]][path[i]];
            if (residual < flow) {
                flow = residual;
            }
        }
        // Apply flow:
        for (size_t i = 1; i < path.size(); i++) {
            _flow[path[i-1]][path[i]] += flow;
            _flow[path[i]][path[i-1]] -= flow;
        }
        return flow;
    }

    /**
     * Used by min cut.
     * Searching for nodes in the side of source in the fully augmented graph.
     */
    void dfs(const size_t u, std::vector<bool> &vis) {
        vis[u] = true;
        for (size_t v : _adjacents[u]) {
            if (vis[v])
                continue;
            TF residual = _capacity[u][v] - _flow[u][v];
            if (residual > 0) { // There are some flow available from u -> v
                dfs(v, vis);
            }
        }
    }

    /**
     * Used my min cost max flow.
     * Finds best cost path from source to sink in the residual graph.
     */
    std::vector<size_t> getPathDijkstra(const Node& source, const Node& sink,
                                        std::vector<TW> &height)
    {
        std::vector<bool> visited(_adjacents.size(), false);
        std::vector<TW> distance(_adjacents.size() + 1, std::numeric_limits<TW>::max()); // max = unreachable
        std::vector<size_t> parent(_adjacents.size(), _adjacents.size()); // size = no predecessor
        // Initiate source node:
        size_t iterator = source.getIndex();
        distance[iterator] = 0;
        // O(N ^ 2) Dijkstra:
        while(iterator != _adjacents.size()) { // size = no other nodes to process
            visited[iterator] = true;
            size_t best = _adjacents.size();
            // Process neighbors:
            for (size_t k = 0; k < _adjacents.size(); k++) {
                if(visited[k])
                    continue;
                // Backward flow:
                if (_flow[k][iterator] != 0) {
                    TW soFar = distance[iterator] - _cost[k][iterator] + height[iterator] - height[k];
                    if (soFar < distance[k]) {
                        distance[k] = soFar;
                        parent[k] = iterator;
                    }
                }
                // Forward flow:
                if (_flow[iterator][k] < _capacity[iterator][k]) {
                    TW soFar = distance[iterator] + _cost[iterator][k] + height[iterator] - height[k];
                    if(soFar < distance[k]) {
                        distance[k] = soFar;
                        parent[k] = iterator;
                    }
                }
                // Choose next best node in Dijkstra:
                if (distance[k] < distance[best]) {
                    best = k;
                }
            }
            iterator = best;
        }
        // Johnson reweighting trick to avoid negative cycles:
        for (size_t k = 0; k < _adjacents.size(); k++) {
            if (visited[k]) {
                height[k] += distance[k];
            }
        }
        // Build flow path:
        std::vector<size_t> path;
        if (!visited[sink.getIndex()]) // Network if full
            return path;
        iterator = sink.getIndex();
        while (iterator != _adjacents.size()) {
            path.push_back(iterator);
            iterator = parent[iterator];
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

public:
    explicit FlowNetwork(const size_t size) {
        _adjacents.assign(size, std::set<size_t>());
        _capacity.assign(size, std::vector<TF>(size, 0));
        _flow.assign(size, std::vector<TF>(size, 0));
        _cost.assign(size, std::vector<TW>(size, 0));
    }

    void addCapacity(const size_t from, const size_t to, TF capacity, TW cost = 1) {
        _adjacents[from].insert(to);
        _adjacents[to].insert(from);
        _capacity[from][to] += capacity;
        _cost[from][to] = cost;
    }

    /**
    * Edmond-Karp algorithm.
    * Time Complexity: O(F * (V + E))
    * Space Complexity: O(V ^ 2)
    */
    TF maxFlow(const Node &source, const Node& sink) {
        TF maxFlow = 0;
        while (true) {
            TF flow = tryAugment(source, sink);
            if (!flow)
                break;
            maxFlow += flow;
        }
        return maxFlow;
    }

    /**
     * maxFlow() should be called before getting edges of max flow.
     */
    std::vector<std::pair<Edge<TW>, TF>> flowEdges() {
        std::vector<std::pair<Edge<TW>, TF>> result;
        for (size_t i = 0; i < _adjacents.size(); i++) {
            for (size_t j : _adjacents[i]) {
                if (_flow[i][j] > 0) {
                    result.emplace_back(Edge<TW>(Node(i), Node(j), 1), _flow[i][j]);
                }
            }
        }
        return result;
    }

    /**
     * maxFlow() should be called before getting nodes in cut of source node.
     */
    std::vector<Node> minCut(const Node &source) {
        std::vector<bool> vis(_adjacents.size(), false);
        dfs(source.getIndex(), vis);
        std::vector<Node> result;
        for (size_t i = 0; i < _adjacents.size(); i++) {
            if (vis[i]) {
                result.emplace_back(i);
            }
        }
        return result;
    }

    /**
     * Johnson Potentials.
     * Time Complexity: O(F * (V ^ 2))
     * Space Complexity: O(V ^ 2)
     */
    std::pair<TF, TW> minCostMaxFlow(const Node& source, const Node& sink)
    {
        TF maxFlow = 0;
        TW minCost = 0;
        std::vector<TW> height(_adjacents.size(), 0); // used for reweighting trick to avoid negative cycles
        while (true) {
            std::vector<size_t> path = getPathDijkstra(source, sink, height);
            if (path.empty())
                break;
            // Calculate flow bottleneck:
            TF pathFlow = std::numeric_limits<TF>::max();
            for (size_t i = 1; i < path.size(); i++) {
                size_t u = path[i-1];
                size_t v = path[i];
                TF residual = _flow[v][u] != 0 ? _flow[v][u] : _capacity[u][v] - _flow[u][v]; // handle reverse flow
                if (residual < pathFlow) { // There are some flow available from u -> v
                    pathFlow = residual;
                }
            }
            maxFlow += pathFlow;
            // Apply flow:
            for (size_t i = 1; i < path.size(); i++) {
                size_t u = path[i-1];
                size_t v = path[i];
                if (_flow[v][u] != 0) { // This is a backward flow
                    _flow[v][u] -= pathFlow;
                    minCost -= pathFlow * _cost[v][u];
                }
                else { // This is a forward flow
                    _flow[u][v] += pathFlow;
                    minCost += pathFlow * _cost[u][v];
                }
            }
        }
        return {maxFlow, minCost};
    }
};