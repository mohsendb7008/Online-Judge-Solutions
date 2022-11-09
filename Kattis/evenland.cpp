#include <bits/stdc++.h>
using namespace std;

// Evenland

const int MAXNM = 100003;

const int MOD = 1000000009;

int n, m, vis[MAXNM];
pair<int, int> e[MAXNM];
set<int> adj[MAXNM];

int nodes, edges;

void dfs(int u){
    vis[u] = 1;
    nodes += 1;
    edges += adj[u].size();
    for(int q: adj[u]){
        pair<int, int> p = e[q];
        int v = (p.first == u) ? p.second : p.first;
        if(!vis[v]){
            dfs(v);
        }
    }
}

int p2[MAXNM];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> e[i].first >> e[i].second;
        e[i].first--, e[i].second--;
        adj[e[i].first].insert(i);
        adj[e[i].second].insert(i);
    }
    p2[0] = 1;
    for(int i = 1; i < MAXNM; i++) {
        p2[i] = (p2[i-1] * 2) % MOD;
    }
    long long int ans = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            nodes = 0, edges = 0;
            dfs(i);
            edges /= 2;
            ans = (ans * p2[edges - nodes + 1]) % MOD;
        }
    }
    cout << ans << endl;
}