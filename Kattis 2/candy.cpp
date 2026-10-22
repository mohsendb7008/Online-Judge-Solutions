#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, ll>>> bags(n);
    map<int, int> ids;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        while (m--) {
            int t;
            ll c;
            cin >> t >> c;

            if (!ids.count(abs(t)))
                ids[abs(t)] = ids.size();

            int id = ids[abs(t)];
            bags[i].push_back({id, t > 0 ? c : -c});
        }
    }

    int k = ids.size();
    vector<ll> score(n, 0);
    ll ans = 0;

    function<void(int)> dfs = [&](int pos) {
        if (pos == k) {
            ll total = 0;

            for (ll x : score)
                total += max(0LL, x);

            ans = max(ans, total);
            return;
        }

        vector<pair<int, ll>> changes;

        for (int i = 0; i < n; i++) {
            for (auto [id, val] : bags[i]) {
                if (id == pos)
                    changes.push_back({i, val});
            }
        }

        for (auto [i, val] : changes)
            score[i] += val;

        dfs(pos + 1);

        for (auto [i, val] : changes)
            score[i] -= 2 * val;

        dfs(pos + 1);

        for (auto [i, val] : changes)
            score[i] += val;
    };

    dfs(0);

    cout << ans << '\n';
}
