#include <bits/stdc++.h>
using namespace std;

// Driving Range

const int maxn = 1e6;

int n, m;
map<pair<int, int>, int> edges;

void relax(int x, int y, int w){
    if(edges.find({x, y}) == edges.end())
        edges[{x, y}] = w;
    else
        edges[{x, y}] = min(edges[{x, y}], w);
}

vector<pair<int, int>> adj[maxn + 3];
bool taken[maxn + 3], ok = false;
int cnt = 0, ans = -1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void prim(int u){
    taken[u] = 1, cnt++;
    for(auto v : adj[u])
        if(!taken[v.first])
            pq.push({v.second, v.first});
}

int main(){
    cin >> n >> m;
    if(n <= 1){
        cout << 0 << endl;
        return 0;
    }
    int x, y, w;
    while(m--)
        cin >> x >> y >> w, relax(min(x, y), max(x, y), w);
    for(auto p : edges)
        adj[p.first.first].push_back({p.first.second, p.second}), adj[p.first.second].push_back({p.first.first, p.second});
    prim(0);
    while(!pq.empty()){
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(taken[u])
            continue;
        if(cnt == n-1)
            ok = true;
        ans = max(ans, w);
        prim(u);
    }
    if(!ok)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;      
}