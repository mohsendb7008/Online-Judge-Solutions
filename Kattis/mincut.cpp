#include <bits/stdc++.h>
using namespace std;

// Minimum Cut

int n, m, s, t, c[503][503], flow[503][503], par[503];
vector<int> adj[503];

int augment(){
    fill_n(par, n, -1);
    par[s] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({s, INT_MAX});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == t)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(1){
        int f = augment();
        if(!f)
            break;
        ans += f;
        int it = t;
        while(it != s){
            flow[par[it]][it] += f;
            flow[it][par[it]] -= f;
            it = par[it];
        }
    }
    return ans;
}

bool vis[503];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v] && c[u][v] - flow[u][v] > 0)
            dfs(v);
}

int main(){
    cin >> n >> m >> s >> t;
    int u, v, g;
    while(m--)
        cin >> u >> v >> g, c[u][v] = g, adj[u].push_back(v), adj[v].push_back(u);
    max_flow();
    dfs(s);
    cout << count(vis, vis + n, true) << endl;
    for(int i = 0; i < n; i++)
        if(vis[i])
            cout << i << endl;
}