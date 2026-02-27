#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, indegree[40003], dis[40003];
vector<int> adj[40003];
unordered_map<int, int> dep;

int main() {
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        dep.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
            adj[i].clear();
            int m;
            cin >> m;
            for (int j = 0; j < m-1; j++) {
                int r;
                cin >> r;
                auto it = dep.find(r);
                if (it != dep.end()) {
                    adj[it->second].push_back(i);
                    indegree[i]++;
                }
            }
            int w;
            cin >> w;
            dep[w] = i;
        }
        queue<int> bfs;
        for (int i = 0; i < n; i++) {
            if (indegree[i]) {
                dis[i] = numeric_limits<int>::max();
            } else {
                dis[i] = 0;
                bfs.push(i);
            }
        }
        int ans = 0;
        while (!bfs.empty()) {
            const int u = bfs.front();
            bfs.pop();
            ans = max(ans, dis[u]);
            for (const int v : adj[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    dis[v] = dis[u] + 1;
                    bfs.push(v);
                }
            }
        }
        cout << t + 1 << " " << ans + 1 << endl;
    }
}