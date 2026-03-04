#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define inf numeric_limits<long>::max()

int n, m;
long c, dis[100003];
vector<pair<int, pair<long, pair<long, long>>>> adj[100003];
priority_queue<pair<long, int>> pq;

int main() {
    cin >> n >> m >> c;
    while (m--) {
        int a, b;
        long t, l, r;
        cin >> a >> b >> t >> l >> r;
        a--, b--;
        adj[a].emplace_back(b, make_pair(t, make_pair(l, r)));
        adj[b].emplace_back(a, make_pair(t, make_pair(l, r)));
    }
    fill_n(dis, n, inf);
    dis[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        const long w = -pq.top().first;
        const int u = pq.top().second;
        pq.pop();
        if (dis[u] < w)
            continue;
        for (const auto &e: adj[u]) {
            const int v = e.first;
            const long t = e.second.first;
            const long l = e.second.second.first;
            const long r = e.second.second.second;
            long cost = w + t;
            if (w % c < l) {
                cost += l - w % c;
            }
            if (w % c > r) {
                cost += c - w % c + l;
            }
            if (cost < dis[v]) {
                dis[v] = cost;
                pq.emplace(-cost, v);
            }
        }
    }
    cout << dis[n-1] << endl;
}