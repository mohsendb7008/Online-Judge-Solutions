#include <bits/stdc++.h>
using namespace std;

// Invasion

const int maxn = 1e4 + 3;
const int inf = INT_MAX;

int n, m, a, k, dis[maxn];
vector<pair<int, int>> adj[maxn];
set<int> frontier;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

int main(){
    while(1){
        cin >> n >> m >> a >> k;
        if(!(n + m + a + k))
            break;
        frontier.clear();
        for(int i = 0; i < n; i++)
            dis[i] = inf, adj[i].clear(), frontier.insert(i);
        int x, y, w;
        while(m--)
            cin >> x >> y >> w, adj[x-1].push_back({y-1, w}), adj[y-1].push_back({x-1, w});
        while(a--){
            cin >> x, x--, dis[x] = 0, dij.push({0, x});
            while(!dij.empty()){
                int u = dij.top().second, w = dij.top().first;
                dij.pop();
                if(dis[u] < w)
                    continue;
                if(w < k)
                    frontier.erase(u);
                for(pair<int, int> v : adj[u])
                    if(w + v.second < dis[v.first])
                        dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
            }
            cout << frontier.size() << endl;
        }
    }
}