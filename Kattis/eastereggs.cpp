#include <bits/stdc++.h>
using namespace std;

// Easter Eggs

int n, b, r, vis[253], match[253];
double bx[253], by[253], rx[253], ry[253];
vector<int> adj[253];

bool aug(int u){
    if(vis[u])
        return 0;
    vis[u] = 1;
    for(int v : adj[u])
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    return 0;
}

bool judge(double d){
    for(int i = 0; i < b; i++)
        adj[i].clear();
    for(int i = 0; i < b; i++)
        for(int j = 0; j < r; j++){
            double dx = bx[i] - rx[j], dy = by[i] - ry[j];
            if(dx * dx + dy * dy < d * d)
                adj[i].push_back(j);
        }
    int mcbm = 0;
    fill_n(match, r, -1);
    for(int i = 0; i < b; i++)
        fill_n(vis, b, 0), mcbm += aug(i);
    return r + b - mcbm >= n;
}

int main(){
    cin >> n >> b >> r;
    for(int i = 0; i < b; i++)
        cin >> bx[i] >> by[i];
    for(int i = 0; i < r; i++)
        cin >> rx[i] >> ry[i];
    double lo = 0, hi = 2e8;
    while(fabs(hi - lo) > 1e-9){
        double mid = (lo + hi) / 2;
        if(judge(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(7) << lo << endl;
}