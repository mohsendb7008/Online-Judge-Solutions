#include <bits/stdc++.h>
using namespace std;

// Human Cannonball Run

double sx, sy, dx, dy;
int n;
pair<double, double> a[103];
vector<pair<int, double>> adjs[103];
double dist[103];

double dis(int i, int j){
    double dx = a[i].first - a[j].first, dy = a[i].second - a[j].second;
    return sqrt(dx * dx + dy * dy);
}

void dijkstra(){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    dist[n] = 0;
    pq.push({0, n});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        double d = p.first;
        int u = p.second;
        if(d > dist[u])
            continue;
        for(auto x : adjs[u])
            if(dist[x.first] > dist[u] + x.second){
                dist[x.first] = dist[u] + x.second;
                pq.push({dist[x.first], x.first});
            }
    }
}

int main(){
    cin >> sx >> sy >> dx >> dy >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    a[n] = {sx, sy}, a[n + 1] = {dx, dy};
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            double d = dis(i, j);
            adjs[i].push_back({j, 2 + fabs(d - 50) / 5});
            adjs[j].push_back({i, 2 + fabs(d - 50) / 5});
        }
    for(int i = 0; i < n; i++)
        adjs[n].push_back({i, dis(i, n) / 5});
    for(int i = 0; i < n; i++)
        adjs[i].push_back({n + 1, 2 + fabs(dis(i, n + 1) - 50) / 5});
    adjs[n].push_back({n + 1, dis(n, n + 1) / 5});
    fill_n(dist, n + 2, INT_MAX);
    dijkstra();
    cout << fixed << setprecision(4) << dist[n + 1] << endl;
}