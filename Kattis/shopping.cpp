#include <bits/stdc++.h>
using namespace std;

// Shopping

#define num long long int

const int maxn = 1e5 + 3;

int n, m, s;
vector<pair<int, num>> adj[maxn];
int stores[13];
num tmp[maxn], dist[13][13];

inline void dijkstra(int store){
    int src = stores[store];
    fill_n(tmp, n, LLONG_MAX);
    priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;
    tmp[src] = 0;
    dij.push({0, src});
    while(!dij.empty()){
        int u = dij.top().second;
        num w = dij.top().first;
        dij.pop();
        if(tmp[u] < w)
            continue;
        for(pair<int, num> v : adj[u])
            if(w + v.second < tmp[v.first]){
                tmp[v.first] = w + v.second;
                dij.push({tmp[v.first], v.first});
            }        
    }
    for(int store2 = 0; store2 < s; store2++)
        dist[store][store2] = tmp[stores[store2]];
}

num dp[(1<<10)+3][13];

int main(){
    cin >> n >> m;
    int x, y;
    num w;
    while(m--)
        cin >> x >> y >> w, adj[x].push_back({y, w}), adj[y].push_back({x, w});
    cin >> s, s++;
    stores[0] = 0;
    for(int i = 1; i < s; i++)
        cin >> stores[i];
    for(int i = 0; i < s; i++)
        dijkstra(i);
    for(int mask = 1; mask < (1<<(s-1)); mask++)
        for(int node = 0; node < s - 1; node++)
            if(mask & (1 << node)){
                if(mask == 1 << node)
                    dp[mask][node] = dist[0][node+1];
                else{
                    dp[mask][node] = LLONG_MAX;
                    for(int prevy = 0; prevy < s - 1; prevy++)
                        if(prevy != node && (mask & (1 << prevy)))
                            dp[mask][node] = min(dp[mask][node], dp[mask - (1<<node)][prevy] + dist[prevy+1][node+1]);
                }
            }
    num ans = LLONG_MAX;
    for(int node = 0; node < s - 1; node++)
        ans = min(ans, dp[(1<<(s-1))-1][node] + dist[node + 1][0]);
    cout << ans << endl; 
}