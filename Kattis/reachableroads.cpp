#include <bits/stdc++.h>
using namespace std;

// Reachable Roads

int t, n, m;
vector<int> adj[1003];
bool vis[1003];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int cc(){
    fill_n(vis, n, false);
    int ans = 0;
    for(int u = 0; u < n; u++)
        if(!vis[u])
            ans++, dfs(u);
    return ans;    
}


int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y;
        while(m--)
            cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
        cout << cc() - 1 << endl;
    }
}