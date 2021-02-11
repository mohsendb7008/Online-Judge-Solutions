#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MAX;

int n, m;
vector<pair<int, num>> adj[103], radj[103]; 
num dis[103][103], dp[103][103], ans[103];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;

num cdp(int u, int src){
    if(dp[src][u] != -1)
        return dp[src][u];
    if(u == src)
        return dp[src][u] = 1;
    num sum = 0;
    for(auto v : radj[u])
        if(dis[src][v.first] != inf && dis[src][v.first] + v.second == dis[src][u])
            sum += cdp(v.first, src);
    return dp[src][u] = sum;
}

int main(){
    cin >> n >> m;
    int u, v;
    num w;
    while(m--)
        cin >> u >> v >> w, adj[u-1].push_back({v-1, w}), radj[v-1].push_back({u-1, w});
    for(int src = 0; src < n; src++){
        for(int u = 0; u < n; u++)
            dis[src][u] = inf, dp[src][u] = -1;
        dis[src][src] = 0;
        dij.push({0, src});
        while(!dij.empty()){
            int u = dij.top().second;
            num w = dij.top().first;
            dij.pop();
            if(dis[src][u] < w)
                continue;
            for(auto v : adj[u])
                if(w + v.second < dis[src][v.first])
                    dis[src][v.first] = w + v.second, dij.push({dis[src][v.first], v.first});
        }
        for(int u = 0; u < n; u++)
            if(dis[src][u] != inf)
                cdp(u, src);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(j != i && dis[i][j] != inf)
                for(int k = 0; k < n; k++)
                    if(k != i && k != j && dis[j][k] != inf && dis[i][k] != inf && dis[i][j] + dis[j][k] == dis[i][k])
                        ans[j] += dp[i][j] * dp[j][k];
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
}