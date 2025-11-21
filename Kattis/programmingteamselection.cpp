#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m;
        cin >> m;
        if (!cin || m == 0) break;

        vector<pair<string, string>> edges(m);
        set<string> names;
        for (int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
            names.insert(edges[i].first);
            names.insert(edges[i].second);
        }

        vector<string> idx(names.begin(), names.end());
        int n = idx.size();
        unordered_map<string, int> id;
        for (int i = 0; i < n; i++) id[idx[i]] = i;

        bool good[15][15] = {};
        for (auto &e : edges) {
            int a = id[e.first];
            int b = id[e.second];
            good[a][b] = good[b][a] = true;
        }

        if (n % 3 != 0) {
            cout << "impossible\n";
            continue;
        }

        int N = 1 << n;
        vector<bool> dp(N, false);
        dp[0] = true;

        for (int mask = 1; mask < N; mask++) {
            if (__builtin_popcount(mask) % 3 != 0) continue;
            if (!dp[mask]) {
                int i = __builtin_ctz(mask);
                for (int j = i + 1; j < n; j++) if (mask & (1 << j)) {
                    if (!good[i][j]) continue;
                    for (int k = j + 1; k < n; k++) if (mask & (1 << k)) {
                        if (good[i][k] && good[j][k]) {
                            int nxt = mask ^ (1 << i) ^ (1 << j) ^ (1 << k);
                            if (dp[nxt]) {
                                dp[mask] = true;
                                goto done;
                            }
                        }
                    }
                }
            }
        done:;
        }

        cout << (dp[N - 1] ? "possible\n" : "impossible\n");
    }
    return 0;
}
