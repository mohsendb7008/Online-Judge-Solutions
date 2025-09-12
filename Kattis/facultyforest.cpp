#include <bits/stdc++.h>
using namespace std;

int n, cc = 0;
vector<int> adj[100003];
bool vis[100003];
int id[100003], ccsize[100003];

void dfs(int u){
    vis[u] = true;
    id[u] = cc;
    ccsize[cc]++;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    int m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill_n(vis, n, false);
    for(int u = 0; u < n; u++)
        if(!vis[u])
            dfs(u), cc++;
    
    cout << cc << endl;
}