#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m, vis[maxn];
vector<int> adj[maxn];

void dfs(int u, int h){
    vis[u] = h % 2;
    for(int v : adj[u])
        if(vis[v] == -1)
            dfs(v, h + 1);
}

int main(){
    int u, v;
    cin >> n >> m;
    while(m--)
        cin >> u >> v, adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);
    for(int i = 0; i < n; i++)
        if(adj[i].empty()){
            cout << "No" << endl;
            return 0;
        }
    fill_n(vis, n, -1);
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            dfs(i, 0);
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++)
        cout << vis[i];
    cout << endl;
}