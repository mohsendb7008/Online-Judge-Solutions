#include <bits/stdc++.h>
using namespace std;

// Dungeon master

int n, m, o;
char g[33][33][33];
int dis[33][33][33];
queue<pair<int, pair<int, int>>> bfs;

int adjR[6]{1, -1, 0, 0, 0, 0};
int adjC[6]{0, 0, 1, -1, 0, 0};
int adjH[6]{0, 0, 0, 0, 1, -1};

int main(){
    while(cin >> n >> m >> o){
        if(!(n + m + o))
            break;
        pair<int, pair<int, int>> src, dst;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < o; k++){
                    cin >> g[i][j][k];
                    if(g[i][j][k] == 'S')
                        g[i][j][k] = '.', src = {i, {j, k}};
                    if(g[i][j][k] == 'E')
                        g[i][j][k] = '.', dst = {i, {j, k}};
                    dis[i][j][k] = INT_MAX;
                }
        dis[src.first][src.second.first][src.second.second] = 0;
        bfs.push(src);
        while(!bfs.empty()){
            int p = bfs.front().first, q = bfs.front().second.first, r = bfs.front().second.second;
            bfs.pop();
            for(int k = 0; k < 6; k++){
                int x = p + adjR[k], y = q + adjC[k], z = r + adjH[k];
                if(x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < o && g[x][y][z] == '.' && dis[x][y][z] == INT_MAX)
                    dis[x][y][z] = dis[p][q][r] + 1, bfs.push({x, {y, z}});
            }
        }
        int ans = dis[dst.first][dst.second.first][dst.second.second];
        if(ans == INT_MAX)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }
}