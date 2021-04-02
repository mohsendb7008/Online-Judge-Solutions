#include <bits/stdc++.h>
using namespace std;

// Ocean Currents

#define inf INT_MAX

int adjR[8]{-1, -1, 0, 1, 1, 1, 0, -1};
int adjC[8]{0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
char g[1002][1002];
int dis[1002][1002];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    int q;
    cin >> q;
    while(q--){
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy, sx--, sy--, dx--, dy--;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dis[i][j] = inf;
        dis[sx][sy] = 0;
        dij.push({0, {sx, sy}});
        while(!dij.empty()){
            int w = dij.top().first, ux = dij.top().second.first, uy = dij.top().second.second;
            dij.pop(); 
            if(dis[ux][uy] < w)
                continue;
            for(int k = 0; k < 8; k++){
                int vx = ux + adjR[k], vy = uy + adjC[k];
                int cost = k != (g[ux][uy] - '0');
                if(vx >= 0 && vx < n && vy >= 0 && vy < m && w + cost < dis[vx][vy])
                    dis[vx][vy] = w + cost, dij.push({w + cost, {vx, vy}});
            }
        }
        cout << dis[dx][dy] << endl;
    }
}