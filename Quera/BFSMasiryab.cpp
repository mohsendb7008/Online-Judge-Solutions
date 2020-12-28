#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
const int inf = -1;

int n, m, s, t, u, v, dis[maxn], par[maxn];
vector<int> adj[maxn], path;
queue<int> bfs;

int main(){
    cin >> n >> m >> s >> t, s--, t--;
    while(m--)
        cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
    fill_n(dis, n, inf);
    dis[s] = 0, par[s] = -1;
    bfs.push(s);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == inf)
                dis[v] = dis[u] + 1, par[v] = u, bfs.push(v);
    }
    cout << dis[t] << endl;
    if(dis[t] == -1)
        return 0;
    for(int it = t; it != -1; it = par[it])
        path.push_back(it);
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] + 1 << " \n"[i == -1];
}