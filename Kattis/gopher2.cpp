#include <bits/stdc++.h>
using namespace std;

// Gopher II

int n, m, match[103], vis[103];
double s, v, xg[103], yg[103], xh[103], yh[103];
vector<int> adj[103];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int main(){
    while(cin >> n >> m >> s >> v){
        for(int i = 0; i < n; i++)
            adj[i].clear();
        for(int i = 0; i < n; i++)
            cin >> xg[i] >> yg[i];
        for(int i = 0; i < m; i++)
            cin >> xh[i] >> yh[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                double dx = xg[i] - xh[j], dy = yg[i] - yh[j];
                if(dx * dx + dy * dy <= s * s * v * v)
                    adj[i].push_back(j);
            }
        fill_n(match, m, -1);
        int mcbm = 0;
        for(int i = 0; i < n; i++)
            fill_n(vis, n, 0), mcbm += augment(i);
        cout << n - mcbm << endl; 
    }
}