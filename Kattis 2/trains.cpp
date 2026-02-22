#include <iostream>
#include <unordered_map>
#include <set>
#include "GraphV1.cpp"
using namespace std;

char buffer[100];
unordered_map<string, int> id;

inline int getId(const string& s) {
    const auto it = id.find(s);
    if (it != id.end())
        return it->second;
    return id[s] = id.size();
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        vector<pair<pair<int, int>, pair<int, int>>> trips;
        int t;
        scanf("%d", &t);
        while (t--) {
            int s;
            scanf("%d", &s);
            s--;
            int h, m;
            string u;
            scanf("%02d:%02d %s", &h, &m, buffer);
            u = buffer;
            int uid = getId(u);
            int ut = 60 * h + m;
            while (s--) {
                int hh, mm;
                string uu;
                scanf("%d:%02d %s", &hh, &mm, buffer);
                uu = buffer;
                int uuid = getId(uu);
                int uut = 60 * hh + mm;
                trips.emplace_back(make_pair(uid, uuid), make_pair(ut, uut));
                uid = uuid;
                ut = (ut + uut) % (24 * 60);
            }
        }
        string u, v;
        scanf("%s", buffer);
        u = buffer;
        scanf("%s", buffer);
        v = buffer;
        int uid = getId(u);
        int vid = getId(v);
        GraphV1<int> g(id.size());
        set<int> allT0;
        for (const auto it : trips) {
            Node x(it.first.first);
            Node y(it.first.second);
            int t0 = it.second.first;
            int w = it.second.second;
            g.addEdge(Edge<int>(x, y, w, t0, 24 * 60));
            if (it.first.first == uid) {
                allT0.insert(t0);
            }
        }
        set<pair<int, int>> ans;
        for (int t0 : allT0) {
            auto result = g.dijkstra(Node(uid), t0);
            int dis = result.getMinDistance(Node(vid)) - t0;
            ans.insert(make_pair(t0, dis));
        }
        set<pair<int, int>> dominate;
        for (auto it : ans) {
            for (auto it2 : ans) {
                if (it2 == it)
                    continue;
                int a1 = it2.second;
                int b1 = (it2.first + it2.second) % (24 * 60);
                int a2 = it.second;
                int b2 = (it.first + it.second) % (24 * 60);
                if (b1 == b2 && a1 < a2) {
                    dominate.insert(it);
                    break;
                }
            }
        }
        for (auto it : ans) {
            if (dominate.find(it) != dominate.end()) {
                continue;
            }
            int i = it.first;
            int j = it.second;
            printf("%02d:%02d %d:%02d\n", i / 60, i % 60, j / 60, j % 60);
        }
        printf("\n");
        id.clear();
    }
}