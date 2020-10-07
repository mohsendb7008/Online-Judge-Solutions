#include <bits/stdc++.h>
using namespace std;

// Single source shortest path, time table

#define inf INT_MAX

struct edge{
    int u, v, t0, P, d;
};

int n, m, q, s;
vector<edge> adj[10003];
int dis[10003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

int main(){
    while(cin >> n >> m >> q >> s){
        if(!(n + m + q + s))
            break;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        while(m--){
            edge e;
            cin >> e.u >> e.v >> e.t0 >> e.P >> e.d;
            adj[e.u].push_back(e);
        }
        fill_n(dis, n, inf);
        dis[s] = 0;
        dij.push({0, s});
        while(!dij.empty()){
            int w = dij.top().first, u = dij.top().second;
            dij.pop();
            if(dis[u] < w)
                continue;
            for(edge v : adj[u]){
                int nw = inf;
                if(w <= v.t0)
                    nw = v.t0 + v.d;
                else if(v.P){
                    int a = (w - v.t0) / v.P + (((w - v.t0) % v.P) ? 1 : 0);
                    nw = a * v.P + v.t0 + v.d;
                }
                if(nw < dis[v.v])
                    dis[v.v] = nw, dij.push({nw, v.v });
            }
        }
        int d;
        while(q--){
            cin >> d;
            if(dis[d] == inf)
                cout << "Impossible" << endl;
            else
                cout << dis[d] << endl;
        }
        cout << endl;
    }   
}