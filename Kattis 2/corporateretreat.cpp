#include <bits/stdc++.h>
using namespace std;

struct TwoSAT {
    int n;
    vector<vector<int>> g, rg;
    vector<int> order, comp, ans;
    vector<bool> vis;

    TwoSAT(int n) : n(n), g(2 * n), rg(2 * n),
                    comp(2 * n, -1), ans(n), vis(2 * n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    void add_or(int u, bool a, int v, bool b) {
        int x = 2 * u + a;
        int y = 2 * v + b;
        add_edge(x ^ 1, y);
        add_edge(y ^ 1, x);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v]) dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, int c) {
        comp[u] = c;
        for (int v : rg[u])
            if (comp[v] == -1) dfs2(v, c);
    }

    bool solve() {
        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs1(i);

        reverse(order.begin(), order.end());

        int c = 0;
        for (int u : order)
            if (comp[u] == -1) dfs2(u, c++);

        for (int i = 0; i < n; i++) {
            if (comp[2 * i] == comp[2 * i + 1])
                return false;
            ans[i] = comp[2 * i + 1] > comp[2 * i];
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n);

    for (auto &[u, v] : edges) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int total = 1;
    for (int i = 0; i < k; i++) total *= 3;

    for (int mask = 0; mask < total; mask++) {
        vector<int> color(n, -1);
        int x = mask;

        for (int i = 0; i < k; i++) {
            color[i] = x % 3;
            x /= 3;
        }

        bool ok = true;

        for (auto [u, v] : edges) {
            if (u < k && v < k && color[u] == color[v]) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;

        vector<array<int, 2>> choices(n);

        for (int u = k; u < n; u++) {
            bool used[3] = {};

            for (int v : adj[u])
                if (v < k) used[color[v]] = true;

            vector<int> available;
            for (int c = 0; c < 3; c++)
                if (!used[c]) available.push_back(c);

            if (available.empty()) {
                ok = false;
                break;
            }

            choices[u] = {available[0], available.back()};
        }

        if (!ok) continue;

        TwoSAT sat(n - k);

        for (auto [u, v] : edges) {
            if (u < k || v < k) continue;

            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    if (choices[u][a] == choices[v][b])
                        sat.add_or(u - k, !a, v - k, !b);
                }
            }
        }

        if (!sat.solve()) continue;

        for (int u = k; u < n; u++)
            color[u] = choices[u][sat.ans[u - k]];

        cout << "possible\n";
        for (int i = 0; i < n; i++)
            cout << color[i] + 1 << (i + 1 == n ? '\n' : ' ');

        return 0;
    }

    cout << "impossible\n";
    return 0;
}
