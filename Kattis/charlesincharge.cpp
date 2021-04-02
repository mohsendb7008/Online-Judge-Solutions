#include <bits/stdc++.h>
using namespace std;

// Charles in Charge

#define num long long int

const int maxn = 1e4 + 3;
const num inf = LLONG_MAX;

int n, m;
num x;
vector<pair<int, num>> adj[maxn];

num dis[maxn];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;

num dijkstra(num limit){
    fill_n(dis, n, inf);
    dis[0] = 0;
    dij.push({0, 0});
    while(!dij.empty()){
        int u = dij.top().second;
        num w = dij.top().first;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, num> v : adj[u])
            if(v.second <= limit && w + v.second < dis[v.first])
                dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
    }
    return dis[n-1];
}

int main(){
    cin >> n >> m >> x;
    int u, v;
    num w;
    while(m--)
        cin >> u >> v >> w, u--, v--, adj[u].push_back({v, w}), adj[v].push_back({u, w});
    num sp = dijkstra(inf);
    num lo = 1, hi = 1000000000;
    while(lo < hi){
        num mid = (lo + hi) / 2;
        num ans = dijkstra(mid);
        if(ans == inf || ans * 100 > sp * (100 + x))
            lo = mid + 1;
        else
            hi = mid;
    }
    cout << lo << endl;
}