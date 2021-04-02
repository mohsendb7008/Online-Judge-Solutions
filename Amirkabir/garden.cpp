#include <bits/stdc++.h>
using namespace std;

const double inf = LLONG_MAX;
int n;
double r[1003], x[1003], y[1003];
vector<pair<double, int>> adjs[1003];

double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return max(0.0, hypot(dx, dy) - (r[i] + r[j]));
}

priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
double dis[1003];

int main(){
    cin >> n;
    r[0] = x[0] = y[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> r[i] >> x[i] >> y[i];
    for(int i = 0; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            adjs[i].push_back({dist(i, j), j}), adjs[j].push_back({dist(i, j), i});
    fill_n(dis, n + 1, inf);
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        double d = p.first;
        if(dis[u] < d)
            continue;
        for(auto x : adjs[u])
            if(dis[x.second] > d + x.first)
                dis[x.second] = d + x.first, pq.push({dis[x.second], x.second});
    }
    cout << fixed << setprecision(7) << dis[n] << endl;
}