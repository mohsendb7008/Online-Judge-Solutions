#include <bits/stdc++.h>
using namespace std;

// Tima goes to Xentopia

#define num long long int

const num inf = LLONG_MAX;

int n, m, k1, k2, s, d;
vector<pair<int, pair<num, int>>> adj[453];
num dis[453][1603];
priority_queue<pair<num, pair<int, pair<int, int>>>, vector<pair<num, pair<int, pair<int, int>>>>, greater<pair<num, pair<int, pair<int, int>>>>> dij;

int main(){
    cin >> n >> m >> k1 >> k2, k1++, k2++;
    int u, v, c;
    num w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w >> c, u--, v--;
        adj[u].push_back({v, {w, c}}), adj[v].push_back({u, {w, c}});
    }
    cin >> s >> d, s--, d--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k1 * k2; j++)
            dis[i][j] = inf;
    dis[s][0] = 0;
    dij.push({0, {s, {0, 0}}});
    while(!dij.empty()){
        auto state = dij.top();
        dij.pop();
        num w = state.first;
        int u = state.second.first, red = state.second.second.first, blue = state.second.second.second;
        int col = red * k2 + blue;
        if(dis[u][col] < w)
            continue;
        if(u == d && red == k1 - 1 && blue == k2 - 1){
            cout << w << endl;
            return 0;
        }
        for(auto p : adj[u]){
            int v = p.first;
            num c = p.second.first;
            int color = p.second.second;
            int vred = red, vblue = blue;
            if(color == 1)
                vred++;
            else if(color == 2)
                vblue++;
            if(vred >= k1 || vblue >= k2)
                continue;
            if(w + c < dis[v][vred * k2 + vblue])
                dis[v][vred * k2 + vblue] = w + c, dij.push({w + c, {v, {vred, vblue}}});
        }
    }
    cout << -1 << endl;
}