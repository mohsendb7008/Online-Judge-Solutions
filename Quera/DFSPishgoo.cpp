#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m, s, t, u, v, vis[maxn];
vector<int> adj[maxn];

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m >> s >> t, s--, t--;
    while(m--)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
    dfs(s);
    cout << (vis[t] ? "YES" : "NO") << endl;
}