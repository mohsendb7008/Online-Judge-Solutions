#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

#define inf numeric_limits<int>::max()

using namespace std;

int n, h1x, h1y, h2x, h2y, s1x, s1y, s2x, s2y, dis[30][30][30][30], p1[30][30][30][30], p2[30][30][30][30];
char g[30][30];

inline bool close(const pair<int, int> &jack, const pair<int, int> &jill, const int limit) {
    const int dx = jack.first - jill.first;
    const int dy = jack.second - jill.second;
    return dx * dx + dy * dy < limit;
}

int adjR[5]{0, 0, -1, 1, 0};
int adjC[5]{1, -1, 0, 0, 0};
char dir[4]{'E', 'W', 'N', 'S'};

inline bool solve(const int limit) {
    if (close({h1x, h1y}, {h2x, h2y}, limit))
        return false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    dis[i][j][p][q] = inf;
                }
            }
        }
    }
    dis[h1x][h1y][h2x][h2y] = 0;
    queue<pair<pair<int, int>, pair<int, int>>> bfs;
    bfs.push({{h1x, h1y}, {h2x, h2y}});
    while (!bfs.empty()) {
        auto [f1, f2] = bfs.front();
        const int x1 = f1.first;
        const int y1 = f1.second;
        const int x2 = f2.first;
        const int y2 = f2.second;
        bfs.pop();
        if (x1 == s1x && y1 == s1y && x2 == s2x && y2 == s2y)
            return true;
        for (int k1 = 0; k1 < 5; k1++) {
            if (x1 == s1x && y1 == s1y && k1 < 4)
                continue;
            if (!(x1 == s1x && y1 == s1y) && k1 == 4)
                continue;
            const int a1 = x1 + adjR[k1];
            const int b1 = y1 + adjC[k1];
            if (a1 < 0 || a1 >= n || b1 < 0 || b1 >= n || g[a1][b1] == '*' || g[a1][b1] == 'h' || g[a1][b1] == 's')
                continue;
            for (int k2 = 0; k2 < 5; k2++) {
                if (x2 == s2x && y2 == s2y && k2 < 4)
                    continue;
                if (!(x2 == s2x && y2 == s2y) && k2 == 4)
                    continue;
                const int a2 = x2 + adjR[k2];
                const int b2 = y2 + adjC[k2];
                if (a2 < 0 || a2 >= n || b2 < 0 || b2 >= n || g[a2][b2] == '*' || g[a2][b2] == 'H' || g[a2][b2] == 'S')
                    continue;
                if (dis[a1][b1][a2][b2] < inf || close({a1, b1}, {a2, b2}, limit))
                    continue;
                dis[a1][b1][a2][b2] = dis[x1][y1][x2][y2] + 1;
                p1[a1][b1][a2][b2] = k1;
                p2[a1][b1][a2][b2] = k2;
                bfs.push({{a1, b1}, {a2, b2}});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'H') {
                    h1x = i, h1y = j;
                }
                if (g[i][j] == 'h') {
                    h2x = i, h2y = j;
                }
                if (g[i][j] == 'S') {
                    s1x = i, s1y = j;
                }
                if (g[i][j] == 's') {
                    s2x = i, s2y = j;
                }
            }
        }
        int lo = 0, hi = 2 * (n - 1) * (n - 1);
        while (lo < hi) {
            const int mid = (lo + hi) / 2 + (lo + hi) % 2;
            if (solve(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        solve(lo);
        string d1, d2;
        int i1x = s1x, i1y = s1y, i2x = s2x, i2y = s2y;
        while (!(i1x == h1x && i1y == h1y && i2x == h2x && i2y == h2y)) {
            const int k1 = p1[i1x][i1y][i2x][i2y];
            if (k1 < 4)
                d1.push_back(dir[k1]);
            const int k2 = p2[i1x][i1y][i2x][i2y];
            if (k2 < 4)
                d2.push_back(dir[k2]);
            i1x -= adjR[k1];
            i1y -= adjC[k1];
            i2x -= adjR[k2];
            i2y -= adjC[k2];
        }
        reverse(d1.begin(), d1.end());
        reverse(d2.begin(), d2.end());
        cout << sqrt(lo) << '\n';
        cout << d1 << '\n';
        cout << d2 << '\n';
        cout << '\n';
    }
}