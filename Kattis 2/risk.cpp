#include <iostream>
#include "FlowNetwork.cpp"

using namespace std;

int n, a[103];
bool border[103];
char g[103][103];

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            border[i] = false;
            for (int j = 0; j < n; j++) {
                if (!a[j] && g[i][j] == 'Y') {
                    border[i] = true;
                    break;
                }
            }
        }
        int lo = 1, hi = 10000;
        while (lo < hi) {
            const int mid = (lo + hi) / 2 + (lo + hi) % 2;
            FlowNetwork<> network(2 * n + 2);
            const int source = 2 * n;
            const int sink = 2 * n + 1;
            for (int i = 0; i < n; i++) {
                network.addCapacity(source, i, a[i]);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && g[i][j] == 'N')
                        continue;
                    if (a[i] && a[j]) {
                        network.addCapacity(i, n + j, a[i]);
                    }
                }
            }
            int required = 0;
            for (int i = 0; i < n; i++) {
                const int need = a[i] ? (border[i] ? mid : 1) : 0;
                network.addCapacity(n + i, sink, need);
                required += need;
            }
            const bool ok = network.maxFlow(Node(source), Node(sink)) == required;
            if (ok) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << endl;
    }
}