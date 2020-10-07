#include <bits/stdc++.h>
using namespace std;

// Communications Satellite

const int maxn = 2003;

int n, x[maxn], y[maxn], r[maxn], par[maxn], ran[maxn];
vector<pair<double, pair<int, int>>> edges;

inline double dist(int i, int j){
    double deltax = x[i] - x[j], deltay = y[i] - y[j];
    return sqrt(deltax * deltax + deltay * deltay);
}

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

inline bool umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return false;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
    iota(par, par + n, 0);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            edges.push_back({dist(i, j) - r[i] - r[j], {i, j}});
    sort(edges.begin(), edges.end());
    double ans = 0;
    for(auto edge : edges)
        if(umerge(edge.second.first, edge.second.second))
            ans += edge.first;
    cout << fixed << setprecision(10) << ans << endl;       
}