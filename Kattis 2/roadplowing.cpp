#include <iostream>
#include "EulerGraph.cpp"

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    EulerGraph<> g(n);
    while (c--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.addEdge(Edge<>(Node(u), Node(v), 0));
        g.addEdge(Edge<>(Node(v), Node(u), 1));
    }
    if (!g.isEulerian())
        return 1;
    const auto path = g.getEulerianNodes();
    for (auto it : path) {
        cout << it.getIndex() + 1 << " ";
    }
    cout << endl;
}