#include <bits/stdc++.h>
using namespace std;

// Facility Locations

int n, m, k, x;
vector<int> adj[203];
bool vis[203];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> m >> n >> k;
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++){
            cin >> x;
            if(!x)
                adj[i].push_back(n + j), adj[n + j].push_back(i);
        }
    for(int i = 0; i < n; i++)
        if(adj[i].empty()){
            cout << "no" << endl;
            return 0;
        }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            ans++, dfs(i);
    if(ans <= k)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}