#include <bits/stdc++.h>
using namespace std;

// Single source shortest path, negative weights

#define minf INT_MIN
#define inf INT_MAX

int n, m, q, s;
long long int dis[1003];
pair<int, pair<int, int>> edges[5003];

int main(){
    while(cin >> n >> m >> q >> s){
        if(!(n + m + q + s))
            break;
        for(int i = 0; i < m; i++)
            cin >> edges[i].first >> edges[i].second.first >> edges[i].second.second;
        fill_n(dis, n, inf);
        dis[s] = 0;
        for(int _ = 0; _ < n - 1; _++)
            for(int i = 0; i < m; i++){
                int u = edges[i].first, v = edges[i].second.first, w = edges[i].second.second;
                if(dis[u] != inf)
                    dis[v] = min(dis[v], dis[u] + w);
            }
        for(int _ = 0; _ < n - 1; _++)
            for(int i = 0; i < m; i++){
                int u = edges[i].first, v = edges[i].second.first, w = edges[i].second.second;
                if(dis[u] != inf && dis[u] + w < dis[v])
                    dis[v] = minf;
            }
        int x;
        while(q--){
            cin >> x;
            if(dis[x] == minf)
                cout << "-Infinity" << endl;
            else if(dis[x] == inf)
                cout << "Impossible" << endl;
            else
                cout << dis[x] << endl;
        }
        cout << endl;
    }
}