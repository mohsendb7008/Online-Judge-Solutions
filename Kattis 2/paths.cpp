#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> color(n);
    for (int &c : color) {
        cin >> c;
        --c;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s = 1 << k;
    vector<vector<long long>> dp(s, vector<long long>(n, 0));

    for (int v = 0; v < n; v++) {
        dp[1 << color[v]][v] = 1;
    }

    long long ans = 0;

    for (int mask = 1; mask < s; mask++) {
        for (int v = 0; v < n; v++) {
            if (!dp[mask][v]) continue;

            for (int u : adj[v]) {
                int bit = 1 << color[u];
                if (mask & bit) continue;

                dp[mask | bit][u] += dp[mask][v];
                ans += dp[mask][v];
            }
        }
    }

    cout << ans << '\n';
}
