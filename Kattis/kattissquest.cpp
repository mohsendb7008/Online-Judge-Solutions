#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    map<int, multiset<int>> quests;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int e, g;
            cin >> e >> g;
            quests[e].insert(g);
        } else {
            long long x, gold = 0;
            cin >> x;
            while (true) {
                auto it = quests.upper_bound((int)x);
                if (it == quests.begin()) break;
                --it;
                int e = it->first;
                auto &ms = it->second;
                int g = *prev(ms.end());
                x -= e;
                gold += g;
                ms.erase(prev(ms.end()));
                if (ms.empty()) quests.erase(it);
            }
            cout << gold << "\n";
        }
    }
}
