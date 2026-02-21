#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, xS, yS, xR, yR;
int adjR[4] {0, 0, -1, 1};
int adjC[4] {1, -1, 0, 0};
int minDistanceToEnemy[1000][1000];
int dis[1000][1000];

inline bool canUse(const int x, const int y, const int d) {
    return minDistanceToEnemy[x][y] >= d;
}

inline int sp(const int d) {
    if (!canUse(xS, yS, d) || !canUse(xR, yR, d)) {
        return numeric_limits<int>::max();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dis[i][j] = numeric_limits<int>::max();
        }
    }
    queue<pair<int, int>> bfs;
    dis[xS][yS] = 0;
    bfs.emplace(xS, yS);
    while (!bfs.empty()) {
        const int x = bfs.front().first;
        const int y = bfs.front().second;
        bfs.pop();
        for (int k = 0; k < 4; k++) {
            const int u = x + adjR[k];
            const int v = y + adjC[k];
            if (u >= 0 && u < n && v >= 0 && v < m && dis[u][v] == numeric_limits<int>::max() && canUse(u, v, d)) {
                dis[u][v] = dis[x][y] + 1;
                if (u == xR && v == yR) {
                    return dis[u][v];
                }
                bfs.emplace(u, v);
            }
        }
    }
    return numeric_limits<int>::max();
}

int main() {
    int q;
    cin >> q >> n >> m;
    cin >> xS >> yS >> xR >> yR;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            minDistanceToEnemy[x][y] = numeric_limits<int>::max();
        }
    }
    queue<pair<int, int>> bfs;
    while (q--) {
        int x, y;
        cin >> x >> y;
        minDistanceToEnemy[x][y] = 0;
        bfs.emplace(x, y);
    }
    int lo = 0;
    int hi = 0;
    while (!bfs.empty()) {
        const int x = bfs.front().first;
        const int y = bfs.front().second;
        bfs.pop();
        for (int k = 0; k < 4; k++) {
            const int u = x + adjR[k];
            const int v = y + adjC[k];
            if (u >= 0 && u < n && v >= 0 && v < m && minDistanceToEnemy[u][v] == numeric_limits<int>::max()) {
                minDistanceToEnemy[u][v] = minDistanceToEnemy[x][y] + 1;
                hi = max(hi, minDistanceToEnemy[u][v]);
                bfs.emplace(u, v);
            }
        }
    }
    while (lo < hi) {
        const int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if (sp(mid) == numeric_limits<int>::max()) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    cout << lo << " " << sp(lo) << endl;
}