#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int vis[21], bipartite;
vector<int> adj[21];
long double expected[1001][21][21];

inline void dfs(const int u, const int c) {
    vis[u] = c;
    for (const int v : adj[u]) {
        if (vis[v] == 2) {
            dfs(v, 1 - c);
        } else if (vis[v] == c)
            bipartite = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        vis[i] = 2;
    }
    bipartite = 1;
    dfs(s, 0);
    if (vis[t] == 2 || (bipartite && vis[s] != vis[t])) {
        cout << "never meet" << endl;
        return 0;
    }
    for (int i = 0; i <= 1000; i++) {
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                if (p == q) {
                    expected[i][p][q] = 1000.0 - i;
                } else {
                    expected[i][p][q] = 0.0;
                    if (i && !adj[p].empty() && !adj[q].empty()) {
                        const auto div = static_cast<long double>(adj[p].size() * adj[q].size());
                        for (const int x : adj[p]) {
                            for (const int y : adj[q]) {
                                expected[i][p][q] += expected[i-1][x][y] / div;
                            }
                        }
                    }
                }
            }
        }
    }
    const double ans = expected[1000][s][t];
    cout << fixed << setprecision(10) << ans << endl;
}