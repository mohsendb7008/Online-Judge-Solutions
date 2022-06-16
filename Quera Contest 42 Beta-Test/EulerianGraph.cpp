#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;

int n, deg[maxn];
vector<int> adj[maxn];

bool check_eulerian(){
    int oddcnt = 0;
    for(int i = 0; i < n; i++)
        if(deg[i] % 2)
            oddcnt++;
    if(oddcnt == 1 || oddcnt > 2)
        return false;
    return true;
}

int vis[maxn], cc[maxn], ccs = 0;

void dfs(int u){
    vis[u] = 1;
    cc[u] = ccs;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

bool check_connectivity(){
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            ccs++;
        }
    }
    int united = -1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() > 0){
            united = cc[i];
            break;
        }
    }
    if(united == -1){
        return true;
    }
    for(int i = 0; i < n; i++){
        if(adj[i].size() > 0 && cc[i] != united){
            return false;
        }
    }
    return true;
}

int main(){
    int m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    cout << ((check_eulerian() && check_connectivity()) ? "YES" : "NO") << endl;
}
