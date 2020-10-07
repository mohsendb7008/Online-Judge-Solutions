#include <bits/stdc++.h>
using namespace std;

// Mravi

int n, p[1003], l[1003];
vector<pair<int, pair<double, bool>>> adj[1003];
double memo[1003];

void spread(int u, double f){
    memo[u] = f;
    for(auto p : adj[u]){
        int v = p.first;
        double w = f * p.second.first;
        if(p.second.second)
            w = max(w, w * w);
        spread(v, w);
    }
}

int main(){
    cin >> n;
    fill_n(p, n, -1);
    for(int i = 0; i < n-1; i++){
        int x, y;
        double w;
        bool s;
        cin >> x >> y >> w >> s, x--, y--, w /= 100.0;
        adj[x].push_back({y, {w, s}});
        p[y] = x;
    }
    for(int i = 0; i < n; i++)
        cin >> l[i];
    int r;
    for(int i = 0; i < n; i++)
        if(p[i] == -1){
            r = i;
            break;
        }
    double lo = 0, hi = 2e9;
    while(fabs(hi - lo) > 1e-5){
        double mid = (lo + hi) / 2;
        spread(r, mid);
        bool judge = true;
        for(int i = 0; i < n; i++)
            if(l[i] > memo[i]){
                judge = false;
                break;
            }
        if(judge)
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(3) << lo << endl;
}