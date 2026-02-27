#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

#define inf numeric_limits<long>::max()

int L;
vector<pair<string, long>> ops;

inline string perform(const string& s, const string& o) {
    string d = s;
    for (int i = 0; i < L; i++) {
        if (o[i] == 'N')
            continue;
        if (o[i] == 'F') {
            d[i] = d[i] == '1' ? '0' : '1';
        }
        else if (o[i] == 'S') {
            d[i] = '1';
        }
        else if (o[i] == 'C') {
            d[i] = '0';
        }
    }
    return d;
}

inline long dijkstra(const string& s, const string& d) {
    unordered_map<string, long> dis;
    priority_queue<pair<long, string>> pq;
    dis[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        const auto it = pq.top();
        pq.pop();
        const long &w = it.first;
        const string &u = it.second;
        if (u == d) {
            return -w;
        }
        if (dis.find(u) != dis.end() && dis[u] < w)
            continue;
        for (const auto &op : ops) {
            string v = perform(u, op.first);
            const long soFar = -w + op.second;
            auto it2 = dis.find(v);
            if (it2 == dis.end() || soFar < it2->second) {
                dis[v] = soFar;
                pq.emplace(-soFar, v);
            }
        }
    }
    return inf;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        ops.clear();
        int op, q;
        cin >> L >> op >> q;
        while (op--) {
            string s;
            long c;
            cin >> s >> c;
            ops.emplace_back(s, c);
        }
        while (q--) {
            string s, d;
            cin >> s >> d;
            const long ans = dijkstra(s, d);
            if (ans == inf)
                cout << "NP ";
            else
                cout << ans << " ";
        }
        cout << endl;
    }
}