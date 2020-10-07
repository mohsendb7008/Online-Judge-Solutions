#include <bits/stdc++.h>
using namespace std;

// Lost in Translation

#define inf INT_MAX

int n, m;
map<string, int> id;
vector<pair<int, int>> adj[103];
int dis[103];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;

int main(){
    cin >> n >> m, n++;
    id["English"] = 0;
    string x, y;
    for(int i = 1; i < n; i++)
        cin >> x, id[x] = i;
    int c;
    while(m--){
        cin >> x >> y >> c;
        int i = id[x], j = id[y];
        adj[i].push_back({j, c}), adj[j].push_back({i, c});
    }
    fill_n(dis, n, inf);
    dij.push({0, {0, 0}});
    int ans = 0;
    while(!dij.empty()){
        int w = dij.top().first, c = dij.top().second.first, u = dij.top().second.second;
        dij.pop();
        if(dis[u] != inf)
            continue;
        dis[u] = w;
        ans += c;
        for(pair<int, int> v : adj[u])
            if(dis[v.first] == inf)
                dij.push({dis[u] + 1, {v.second, v.first}});
    }
    if(count(dis, dis + n, inf) == 0)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
}