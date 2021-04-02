#include <bits/stdc++.h>
using namespace std;

// Single source shortest path, non-negative weights

int n, e, q, s;
vector<pair<int, int>> adjs[10003];
int dist[10003];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto p = pq.top();
        int u = p.second;
        int dis = p.first;
        pq.pop();
        if(dis > dist[u])
            continue;
        for(auto v : adjs[u])
            if(v.second + dist[u] < dist[v.first]){
                dist[v.first] = v.second + dist[u];
                pq.push({dist[v.first], v.first});
            }
    }
}

int main(){
    int t = 0;
    while(true){
        cin >> n >> e >> q >> s;
        if(n + e + q + s == 0)
            break;
        t++;
        if(t != 1)
            cout << endl;
        for(int i = 0; i < 10003; i++)
            adjs[i].clear();
        for(int i = 0; i < 10003; i++)
            dist[i] = INT_MAX;
        dist[s] = 0;

        for(int i = 0; i < e; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adjs[u].push_back({v, w});
        }
        
        dijkstra();
        while(q--){
            int v;
            cin >> v;
            if(dist[v] == INT_MAX)
                cout << "Impossible" << endl;
            else
                cout << dist[v] << endl;
        }
    }
}