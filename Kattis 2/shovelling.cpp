#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
char grid[23][23];
int adjR[4] {0, 0, -1, 1};
int adjC[4] {1, -1, 0, 0};
vector<pair<int, int>> adj[403];
int sp[403][403], par[403][403];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> m >> n;
        cout << m << " " << n << endl;
        if (!(n + m))
            break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                adj[i * m + j].clear();
            }
        }
        vector<pair<int, int>> pivots;
        vector<pair<int, int>> homes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#')
                    continue;
                pivots.emplace_back(i, j);
                if (grid[i][j] >= 'A' && grid[i][j] <= 'D') {
                    homes.emplace_back(i, j);
                }
                for (int k = 0; k < 4; k++) {
                    const int x = i + adjR[k];
                    const int y = j + adjC[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
                        continue;
                    adj[i * m + j].emplace_back(x * m + y, grid[x][y] == 'o');
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const int s = i * m + j;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        const int t = x * m + y;
                        sp[s][t] = numeric_limits<int>::max();
                        par[s][t] = -1;
                    }
                }
                deque<pair<int, int>> deq;
                sp[s][s] = 0;
                deq.emplace_back(s, 0);
                while (!deq.empty()) {
                    const int u = deq.front().first;
                    const int w = deq.front().second;
                    deq.pop_front();
                    for (const pair<int, int>& p : adj[u]) {
                        const int v = p.first;
                        const int b = p.second;
                        if (w + b < sp[s][v]) {
                            sp[s][v] = w + b;
                            par[s][v] = u;
                            if (b) {
                                deq.emplace_back(v, w + b);
                            } else {
                                deq.emplace_front(v, w + b);
                            }
                        }
                    }
                }
            }
        }
        int ans = numeric_limits<int>::max();
        int b1x = 0, b1y = 0, b2x = 0, b2y = 0, bh1 = 0, bh2 = 0, bh3 = 0, bh4 = 0;
        for (size_t i = 0; i < pivots.size(); i++) {
            int p1x = pivots[i].first;
            int p1y = pivots[i].second;
            for (size_t j = i; j < pivots.size(); j++) {
                int p2x = pivots[j].first;
                int p2y = pivots[j].second;
                int bridge = sp[p1x * m + p1y][p2x * m + p2y];
                if (bridge == numeric_limits<int>::max())
                    continue;
                if (grid[p1x][p1y] == 'o')
                    bridge++;
                if (bridge > ans)
                    continue;
                vector<pair<int, int>> pivot;
                pivot.emplace_back(p1x, p1y);
                pivot.emplace_back(p2x, p2y);
                const int d1a = sp[pivot[0].first * m + pivot[0].second][homes[0].first * m + homes[0].second];
                const int d1b = sp[pivot[1].first * m + pivot[1].second][homes[0].first * m + homes[0].second];
                int d1 = d1a;
                int h1 = 0;
                if (d1b < d1) {
                    d1 = d1b;
                    h1 = 1;
                }
                if (d1 == numeric_limits<int>::max() || bridge + d1 > ans)
                    continue;
                const int d2a = sp[pivot[0].first * m + pivot[0].second][homes[1].first * m + homes[1].second];
                const int d2b = sp[pivot[1].first * m + pivot[1].second][homes[1].first * m + homes[1].second];
                int d2 = d2a;
                int h2 = 0;
                if (d2b < d2) {
                    d2 = d2b;
                    h2 = 1;
                }
                if (d2 == numeric_limits<int>::max() || bridge + d1 + d2 > ans)
                    continue;
                const int d3a = sp[pivot[0].first * m + pivot[0].second][homes[2].first * m + homes[2].second];
                const int d3b = sp[pivot[1].first * m + pivot[1].second][homes[2].first * m + homes[2].second];
                int d3 = d3a;
                int h3 = 0;
                if (d3b < d3) {
                    d3 = d3b;
                    h3 = 1;
                }
                if (d3 == numeric_limits<int>::max() || bridge + d1 + d2 + d3 > ans)
                    continue;
                const int d4a = sp[pivot[0].first * m + pivot[0].second][homes[3].first * m + homes[3].second];
                const int d4b = sp[pivot[1].first * m + pivot[1].second][homes[3].first * m + homes[3].second];
                int d4 = d4a;
                int h4 = 0;
                if (d4b < d4) {
                    d4 = d4b;
                    h4 = 1;
                }
                if (d4 == numeric_limits<int>::max() || bridge + d1 + d2 + d3 + d4 > ans)
                    continue;
                ans = bridge + d1 + d2 + d3 + d4;
                b1x = p1x;
                b1y = p1y;
                b2x = p2x;
                b2y = p2y;
                bh1 = h1;
                bh2 = h2;
                bh3 = h3;
                bh4 = h4;
            }
        }
        vector<pair<int, int>> pivot;
        pivot.emplace_back(b1x, b1y);
        pivot.emplace_back(b2x, b2y);
        vector<size_t> path;
        auto fillMinPath = [&path](const int u, const int v) -> void {
            int it = v;
            while (par[u][it] != -1) {
                path.push_back(it);
                it = par[u][it];
            }
            path.push_back(u);
        };
        fillMinPath(b1x * m + b1y, b2x * m + b2y);
        fillMinPath(pivot[bh1].first * m + pivot[bh1].second, homes[0].first * m + homes[0].second);
        fillMinPath(pivot[bh2].first * m + pivot[bh2].second, homes[1].first * m + homes[1].second);
        fillMinPath(pivot[bh3].first * m + pivot[bh3].second, homes[2].first * m + homes[2].second);
        fillMinPath(pivot[bh4].first * m + pivot[bh4].second, homes[3].first * m + homes[3].second);
        for (const size_t a : path) {
            const size_t i = a / m;
            const size_t j = a % m;
            if (grid[i][j] == 'o') {
                grid[i][j] = '.';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}