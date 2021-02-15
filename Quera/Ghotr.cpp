#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 3;

int n, vis[maxn], maxd, node_maxd;
vector<int> adj[maxn];

void dfs(int u, int d){
    vis[u] = 1;
    if(d > maxd)
        maxd = d, node_maxd = u;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, d + 1);
}

int main(){
    int u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> u >> v, adj[u-1].push_back(v-1), adj[v-1].push_back(u-1);
    maxd = -1, dfs(0, 0);
    fill_n(vis, n, 0);
    maxd = -1, dfs(node_maxd, 0);
    cout << maxd << endl;
}