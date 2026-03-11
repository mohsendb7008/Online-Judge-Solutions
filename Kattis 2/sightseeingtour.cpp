#include <iostream>
#include "FlowNetwork.cpp"

using namespace std;

int n, in[203], out[203], on[203];
vector<pair<int, int>> edges;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            in[i] = 0;
            out[i] = 0;
            on[i] = 0;
        }
        edges.clear();
        bool hasFixed = false;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            if (u != v) {
                if (w) {
                    out[u]++;
                    in[v]++;
                    hasFixed = true;
                } else {
                    edges.emplace_back(u, v);
                    on[u]++;
                    on[v]++;
                }
            }
        }
        if (hasFixed) {
            FlowNetwork<> network(n + 2);
            int totalNeed = 0;
            for (int i = 0; i < n; i++) {
                if (out[i] > in[i]) {
                    network.addCapacity(n, i, out[i] - in[i]);
                } else if (in[i] > out[i]) {
                    const int need = in[i] - out[i];
                    network.addCapacity(i, n + 1, need);
                    totalNeed += need;
                }
            }
            for (const pair<int, int> e : edges) {
                network.addCapacity(e.first, e.second, 1);
                network.addCapacity(e.second, e.first, 1);
            }
            const bool possible = network.maxFlow(Node(n), Node(n + 1)) == totalNeed;
            cout << (possible ? "possible" : "impossible") << endl;
        } else {
            bool possible = true;
            for (int i = 0; i < n; i++) {
                if (on[i] % 2) {
                    possible = false;
                    break;
                }
            }
            cout << (possible ? "possible" : "impossible") << endl;
        }
    }
}