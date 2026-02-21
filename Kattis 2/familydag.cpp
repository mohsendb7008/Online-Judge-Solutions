#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> g;
unordered_map<string, int> vis;

void dfs(const string& u) {
    vis[u]++;
    if (vis[u] > 1) {
        return;
    }
    for (const string& v : g[u]) {
        dfs(v);
    }
}

int main() {
    string u, v;
    while (cin >> u) {
        if (u == "done") {
            vector<pair<string, bool>> ans;
            for (auto it = vis.begin(); it != vis.end(); ++it) {
                for (auto it2 = vis.begin(); it2 != vis.end(); ++it2) {
                    vis[it2->first] = 0;
                }
                dfs(it->first);
                if (vis[it->first] > 1) {
                    ans.emplace_back(it->first, false);
                    continue;
                }
                for (auto it3 = vis.begin(); it3 != vis.end(); ++it3) {
                    if (vis[it3->first] > 1) {
                        ans.emplace_back(it->first, true);
                        break;
                    }
                }
            }
            sort(ans.begin(), ans.end());
            for (const pair<string, bool> &p : ans) {
                cout << p.first << " " << (p.second ? "hillbilly" : "paradox") << endl;
            }
            cout << endl;
            g.clear();
            vis.clear();
            continue;
        }
        cin >> v >> v;
        g[v].push_back(u);
        vis[u] = vis[v] = 0;
    }
}