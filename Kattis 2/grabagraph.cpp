
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Graph {
    int n;
    vector<tuple<int, int, int>> edges;

    Graph(int n) : n(n) {}

    void add(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    void print() {
        cout << "YES\n";
        cout << n << " " << edges.size() << "\n";

        for (auto [u, v, w] : edges) {
            cout << u << " " << v << " " << w << "\n";
        }
    }
};

Graph buildBash(ll a) {
    Graph g(62);

    for (int i = 3; i <= 62; i++) {
        g.add(1, i, i - 2);

        for (int j = 3; j < i; j++) {
            g.add(j, i, i - j);
        }
    }

    for (int i = 0; i < 60; i++) {
        if ((a >> i) & 1LL) {
            g.add(i + 3, 2, 1000 - (i + 1));
        }
    }

    return g;
}

Graph buildChikapu(ll a) {
    Graph g(88);

    vector<ll> fib(88);
    fib[1] = fib[2] = 1;

    for (int i = 3; i <= 87; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    g.add(1, 3, 1);

    for (int i = 3; i <= 87; i++) {
        int v = i + 1;

        g.add(v, i, 1);

        int u = (i == 3 ? 1 : i - 1);
        g.add(u, v, 2);
    }

    for (int i = 87; i >= 2; i--) {
        if (fib[i] <= a) {
            a -= fib[i];

            int v = (i == 2 ? 3 : i + 1);
            g.add(v, 2, 1000 - (i - 1));
        }
    }

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a;

    while (cin >> a && a != -1) {
        buildBash(a).print();
        buildChikapu(a).print();
    }

    return 0;
}
