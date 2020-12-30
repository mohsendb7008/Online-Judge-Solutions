#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int n, m, f, fire[103][103], dis[103][103];
char g[103][103];
pair<int, int> s, t;
queue<pair<int, int>> bfs;

int adjR[8]{0, 0, 1, -1, -1, -1, 1, 1};
int adjC[8]{1, -1, 0, 0, -1, 1, -1, 1};

int main(){
    while(1){
        cin >> n >> m >> f;
        if(!(n + m + f))
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                fire[i][j] = dis[i][j] = inf;
                if(g[i][j] == 's')
                    s = {i, j};
                else if(g[i][j] == 't')
                    t = {i, j};
                else if(g[i][j] == 'f')
                    fire[i][j] = 0, bfs.push({i, j});
            }
        while(!bfs.empty()){
            auto u = bfs.front();
            bfs.pop();
            int ux = u.first, uy = u.second;
            for(int k = 0; k < 8; k++){
                int vx = ux + adjR[k], vy = uy + adjC[k];
                if(vx >= 0 && vx < n && vy >= 0 && vy < m && fire[vx][vy] == inf)
                    fire[vx][vy] = fire[ux][uy] + f, bfs.push({vx, vy});
            }
        }
        dis[s.first][s.second] = 0;
        bfs.push(s);
        while(!bfs.empty()){
            auto u = bfs.front();
            bfs.pop();
            int ux = u.first, uy = u.second;
            for(int k = 0; k < 4; k++){
                int vx = ux + adjR[k], vy = uy + adjC[k];
                if(vx >= 0 && vx < n && vy >= 0 && vy < m && dis[vx][vy] == inf && dis[ux][uy] + 1 < fire[vx][vy])
                    dis[vx][vy] = dis[ux][uy] + 1, bfs.push({vx, vy});
            }
        }
        if(dis[t.first][t.second] == inf)
            cout << "Impossible" << endl;
        else
            cout << dis[t.first][t.second] << endl;
    }
}