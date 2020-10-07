#include <bits/stdc++.h>
using namespace std;

// Escape Plan

int n, m, t = 0, vis[203], match[203];
double rx[203], ry[203], hx[203], hy[203];
vector<int> adj[203];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = true;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int mcbm(double d){
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            double dx = rx[i] - hx[j], dy = ry[i] - hy[j];
            if(dx * dx + dy * dy <= d * d * 100)
                adj[i].push_back(j);
        }
    fill_n(match, m, -1);
    int ans = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, false), ans += augment(i);
    return ans;
}

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        t++;
        for(int i = 0; i < n; i++)
            cin >> rx[i] >> ry[i];
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> hx[i] >> hy[i];
        cout << "Scenario " << t << endl;
        cout << "In 5 seconds " << mcbm(5) << " robot(s) can escape" << endl;
        cout << "In 10 seconds " << mcbm(10) << " robot(s) can escape" << endl;
        cout << "In 20 seconds " << mcbm(20) << " robot(s) can escape" << endl;
    }
}