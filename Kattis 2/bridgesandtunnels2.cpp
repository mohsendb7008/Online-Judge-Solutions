#include <iostream>
#include <climits>
#include "GraphV1.cpp"

struct route {
    long _out, _in;
    route (const long out, const long in) : _out(out), _in(in) {}
    bool operator <(const route &other) const {
        if (_out == other._out)
            return _in < other._in;
        return _out < other._out;
    }
    route operator +(const route &other) const {
        return { _out + other._out, _in + other._in };
    }
} inf(LLONG_MAX, LLONG_MAX);

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    GraphV1<route> g(n);
    while (m--) {
        int i, j;
        long w;
        char c;
        cin >> i >> j >> w >> c;
        g.addBidirectionalEdge(Edge<route>(Node(i), Node(j),
            route(c == 'O' ? w : 0, c == 'I' ? w : 0)));
    }
    while (p--) {
        int i, j;
        cin >> i >> j;
        auto sp = g.dijkstra(Node(i), route(0, 0), inf);
        route ans = sp.getMinDistance(Node(j));
        if (ans < inf)
            cout << ans._out << " " << ans._out + ans._in << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}