#include <bits/stdc++.h>
using namespace std;

// Get Shorty

int n, m;
vector<pair<int, double>> adj[10003];
double dis[10003];
priority_queue<pair<double, int>> dij;

int main(){
    cout << fixed << setprecision(4);
    while(cin >> n >> m){
        if(!(n + m))
            break;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y;
        double f;
        while(m--)
            cin >> x >> y >> f, adj[x].push_back({y, f}), adj[y].push_back({x, f});
        fill_n(dis, n, 0);
        dis[0] = 1;
        dij.push({1, 0});
        while(!dij.empty()){
            double w = dij.top().first;
            int u = dij.top().second;
            dij.pop();
            if(dis[u] > w)
                continue;
            for(pair<int, double> v : adj[u])
                if(w * v.second > dis[v.first])
                    dis[v.first] = w * v.second, dij.push({w * v.second, v.first});
        }
        cout << dis[n-1] << endl;
    }
}