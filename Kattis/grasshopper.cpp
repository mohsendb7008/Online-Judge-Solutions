#include <bits/stdc++.h>
using namespace std;

// Gregory the Grasshopper

#define inf INT_MAX

int adjR[8]{1, 2, 1, 2, -1, -2, -1, -2};
int adjC[8]{2, 1, -2, -1, 2, 1, -2, -1};

int n, m, sx, sy, dx, dy;
int dis[103][103];
queue<pair<int, int>> bfs;

int main(){
    while(cin >> n >> m >> sx >> sy >> dx >> dy){
        sx--, sy--, dx--, dy--;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dis[i][j] = inf;
        dis[sx][sy] = 0;
        bfs.push({sx, sy});
        while(!bfs.empty()){
            int ux = bfs.front().first, uy = bfs.front().second;
            bfs.pop();
            for(int k = 0; k < 8; k++){
                int vx = ux + adjR[k], vy = uy + adjC[k];
                if(vx >= 0 && vx < n && vy >= 0 && vy < m && dis[vx][vy] == inf)
                    dis[vx][vy] = dis[ux][uy] + 1, bfs.push({vx, vy});
            }
        }
        if(dis[dx][dy] == inf)
            cout << "impossible" << endl;
        else
            cout << dis[dx][dy] << endl;
    }
}