#include <bits/stdc++.h>
using namespace std;

// Beehives

const int maxn = 503;
const int inf = INT_MAX;

int n, m, ans = inf, dist[maxn], par[maxn];
vector<int> adj[maxn];

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    for(int s = 0; s < n; s++){
        fill_n(dist, n, inf);
        dist[s] = 0;
        fill_n(par, n, -1);
        queue<int> bfs;
        bfs.push(s);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(int v : adj[u]){
                if(dist[v] == inf)
                    dist[v] = dist[u] + 1, par[v] = u, bfs.push(v);
                else if(v != par[u])
                    ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
    if(ans == inf)
        cout << "impossible" << endl;
    else 
        cout << ans << endl;
}