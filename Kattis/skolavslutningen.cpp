#include <bits/stdc++.h>
using namespace std;

// Graduation

int n, m, k, adj[26][26], vis[26];
char g[703][703];

void dfs(int u){
    vis[u] = 1;
    for(int v = 0; v < k; v++)
        if(adj[u][v] && !vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    for(int j = 0; j < m; j++)
        for(int u = 1; u < n; u++)
            adj[g[0][j] - 'A'][g[u][j] - 'A'] = adj[g[u][j] - 'A'][g[0][j] - 'A'] = 1;
    int ans = 0;
    for(int i = 0; i < k; i++)
        if(!vis[i])
            ans++, dfs(i);
    cout << ans << endl;
}