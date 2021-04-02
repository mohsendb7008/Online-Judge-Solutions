#include <bits/stdc++.h>
using namespace std;

// George

#define inf INT_MAX

int n, m, a, b, k, g, gp[1003];
map<int, int> adj[1003];
map<pair<int, int>, pair<int, int>> bl;
int dis[1003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

int main(){
    cin >> n >> m >> a >> b >> k >> g;
    for(int i = 0; i < g; i++)
        cin >> gp[i];
    int x, y, w;
    while(m--){
        cin >> x >> y >> w;
        if(adj[x].find(y) == adj[x].end())
            adj[x][y] = w;
        else
            adj[x][y] = min(adj[x][y], w);
        if(adj[y].find(x) == adj[y].end())
            adj[y][x] = w;
        else
            adj[y][x] = min(adj[y][x], w);
    }
    int now = 0;
    for(int i = 1; i < g; i++){
        int u = gp[i-1], v = gp[i];
        int till = now + adj[u][v];
        bl[{u, v}] = bl[{v, u}] = {now, till};
        now = till;
    }
    fill_n(dis, n + 1, inf);
    dis[a] = k, dij.push({k, a});
    while(!dij.empty()){
        int w = dij.top().first, u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, int> p : adj[u]){
            int v = p.first, c = p.second;
            pair<int, int> busy = {0, 0};
            if(bl.find({u, v}) != bl.end())
                busy = bl[{u, v}];
            int nw = w + c;
            if(w >= busy.first && w < busy.second)
                nw += busy.second - w;
            if(nw < dis[v])
                dis[v] = nw, dij.push({nw, v});
        }
    }
    cout << dis[b] - k << endl;
}