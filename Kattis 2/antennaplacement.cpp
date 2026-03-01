#include <iostream>
#include <vector>

// Maximum Cardinality Bipartite Matching
// O(V * E)
class MCBM {
    size_t n, m; // n = |left set|, m = |right set|
    std::vector<std::vector<size_t>> adj; // edges from left set to right set
    std::vector<bool> vis; // for left set dfs
    std::vector<size_t> match; // matched item from left set for right set

    bool augment(const size_t u) {
        if (vis[u])
            return false;
        vis[u] = true;
        for (const size_t v : adj[u]) {
            if (match[v] == n || augment(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

public:
    MCBM(const size_t n, const size_t m) : n(n), m(m) {
        adj.assign(n, std::vector<size_t>());
    }

    void addEdge(const size_t u, const size_t v) {
        adj[u].push_back(v);
    }

    size_t calculate() {
        match.assign(m, n); // n = no match
        size_t mcbm = 0;
        for (size_t i = 0; i < n; i++) {
            vis.assign(n, false);
            mcbm += augment(i);
        }
        return mcbm;
    }
};

using namespace std;

int tc, n, m;
char grid[53][53];
vector<pair<int, int>> points;

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        points.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    points.emplace_back(i, j);
                }
            }
        }
        MCBM g(points.size(), points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                const int d = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
                if (d == 1) {
                    g.addEdge(i, j);
                }
            }
        }
        cout << points.size() - g.calculate() / 2 << endl;
    }
}