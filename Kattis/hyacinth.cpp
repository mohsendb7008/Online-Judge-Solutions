#include <bits/stdc++.h>
using namespace std;

// Hyacinth

const int maxn = 10003;

int n, cnt = 2, f1[maxn], f2[maxn];
vector<int> adj[maxn];

void dfs(int u, int p, int f){
    f1[u] = f, f2[u] = cnt++;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, f2[u]);
}

int main(){
    int u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
    for(int i = 0; i < n; i++)
        if(adj[i].size() == 1){
            u = i;
            break;
        }
    f1[u] = 1, f2[u] = 2;
    dfs(adj[u][0], u, 1);
    for(int i = 0; i < n; i++)
        cout << f1[i] << " " << f2[i] << endl;
}   