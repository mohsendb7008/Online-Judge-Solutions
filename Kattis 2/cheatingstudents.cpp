#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> p(n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    const ll INF = LLONG_MAX;
    vector<ll> dist(n, INF);
    vector<bool> used(n, false);

    dist[0] = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        used[u] = true;
        ans += dist[u];

        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                ll d = abs(p[u].first - p[v].first)
                     + abs(p[u].second - p[v].second);
                dist[v] = min(dist[v], d);
            }
        }
    }

    cout << 2 * ans << '\n';

    return 0;
}
