#include <bits/stdc++.h>
using namespace std;

// Where's My Internet??

int n, m;
vector<int> adj[200003];
bool vis[200003];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1].push_back(y-1), adj[y-1].push_back(x-1);
    fill_n(vis, n, false);
    dfs(0);
    if(count(vis, vis+n, true) == n)
        cout << "Connected" << endl;
    else{
        for(int i = 1; i <= n; i++)
            if(!vis[i-1])
                cout << i << endl;
    }
}