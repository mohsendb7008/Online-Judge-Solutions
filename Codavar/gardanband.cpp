#include <bits/stdc++.h>
using namespace std;

// Gardanband

const int maxn = 1e5 + 3;

int n, vis[maxn];
vector<int> adj[maxn];

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v);
}

int main(){
    cin >> n;
    int u, v;
    for(int i = 0; i < n; i++)
        cin >> u >> v, adj[u-1].push_back(v-1), adj[v-1].push_back(u-1);
    dfs(0);
    cout << (count(vis, vis + n, 0) ? "NO" : "YES") << endl;
}