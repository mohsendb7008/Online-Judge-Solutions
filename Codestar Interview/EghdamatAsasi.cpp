#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int v, e;
vector<int> adjs[maxn];
int vis[maxn];
int dfs_low[maxn], dfs_num[maxn];
int par[maxn];
int cnt = 0;

bool has_bridge = false;

void dfs(int u){
    vis[u] = 1;
    dfs_low[u] = dfs_num[u] = cnt++;
    for(int v : adjs[u]){
        if(!vis[v]){
            par[v] = u;
            dfs(v);
            if(dfs_low[v] > dfs_num[u])
                has_bridge = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    vis[u] = 2;
}

vector<pair<int, int>> edges;
set<int> adjs_index[maxn];

void euler(int u){
    while(!adjs_index[u].empty()){
        int ei = *adjs_index[u].rbegin();
        if(edges[ei].second == u)
            edges[ei] = make_pair(edges[ei].second, edges[ei].first);
        int v = edges[ei].second;
        adjs_index[u].erase(ei);
        adjs_index[v].erase(ei);
        euler(v);
    }
}

int main(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y, x--, y--;
        adjs[x].push_back(y), adjs[y].push_back(x);
        edges.push_back({x, y});
        adjs_index[x].insert(i), adjs_index[y].insert(i);
    }
    dfs(0);
    if(has_bridge){
        cout << "BIKHIAL" << endl;
        return 0;
    }
    cout << "EYVAL" << endl;
    euler(0);
    for(int i = 0; i < e; i++)
        cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl;
}