#include <bits/stdc++.h>
using namespace std;

// Island Hopping

const int maxn = 750;

int n;
double x[maxn + 3], y[maxn + 3];
bool taken[maxn + 3];
vector<pair<int, double>> adj[maxn + 3];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

inline double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

void prim(int u){
    taken[u] = true;
    for(auto v : adj[u])
        if(!taken[v.first])
            pq.push({v.second, v.first});
}

int main(){
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        fill_n(taken, n, false);
        for(int i = 0; i < n; i++)
            adj[i].clear();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                adj[i].push_back({j, dist(i, j)}), adj[j].push_back({i, dist(i, j)});
        prim(0);
        double ans = 0.0;
        while(!pq.empty()){
            int u = pq.top().second;
            double w = pq.top().first;
            pq.pop();
            if(taken[u])
                continue;
            ans += w;
            prim(u);
        }
        cout << ans << endl;
    }
}