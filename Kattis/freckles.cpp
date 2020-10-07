#include <bits/stdc++.h>
using namespace std;

// Freckles

const int maxn = 1003;

int n, par[maxn], ran[maxn];
double x[maxn], y[maxn];
vector<pair<double, pair<int, int>>> edges;

inline double dist(int i, int j){
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

bool umerge(int u, int v){
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
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        iota(par, par + n, 0);
        fill_n(ran, n, 0);
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        edges.clear();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                edges.push_back({dist(i, j), {i, j}});
        sort(edges.begin(), edges.end());
        double ans = 0.0;
        for(auto e : edges)
            if(umerge(e.second.first, e.second.second))
                ans += e.first;
        cout << ans << endl;
        if(!t)
            cout << endl;
    }
}