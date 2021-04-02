#include <bits/stdc++.h>
using namespace std;

// Detour

#define num long long int
#define inf LLONG_MAX

int n, m, par[100003];
vector<pair<int, num>> adj[100003];
num dis[100003];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;
bool vis[100003];
set<pair<int, int>> forbid;

void dag(int u){
    vis[u] = 1;
    if(dis[u] == inf)
        return;
    for(pair<int, num> v : adj[u])
        if(dis[v.first] != inf && dis[v.first] + v.second == dis[u]){
            forbid.insert({u, v.first});
            if(!vis[v.first])
                dag(v.first);
        }
}

void dfs(int u){
    dis[u] = 1;
    for(pair<int, num> v : adj[u])
        if(!dis[v.first] && forbid.find({u, v.first}) == forbid.end())
            par[v.first] = u, dfs(v.first);
}

vector<int> path;

int main(){
    cin >> n >> m;
    int x, y;
    num w;
    while(m--){
        cin >> x >> y >> w;
        adj[x].push_back({y, w}), adj[y].push_back({x, w});
    }
    fill_n(dis, n, inf), fill_n(par, n, -1);
    dis[1] = 0, dij.push({0, 1});
    while(!dij.empty()){
        num w = dij.top().first;
        int u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, num> v : adj[u])
            if(w + v.second < dis[v.first])
                dis[v.first] = w + v.second, par[v.first] = u, dij.push({dis[v.first], v.first});
    }
    for(int i = 0; i < n; i++)
        if(!vis[i])
            dag(i);
    fill_n(dis, n, 0), fill_n(par, n, -1);
    dfs(0);
    if(!dis[1]){
        cout << "impossible" << endl;
        return 0;
    }
    int it = 1;
    while(it != -1)
        path.push_back(it), it = par[it];
    cout << path.size() << " ";
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}