#include <bits/stdc++.h>
using namespace std;

// Slikar

#define inf INT_MAX

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

int n, m;
char g[52][52];
pair<int, int> src, dst;
int dis[52][52];
queue<pair<char, pair<int, int>>> bfs;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S')
                g[i][j] = '.', src = {i, j};
            if(g[i][j] == 'D')
                g[i][j] = '.', dst = {i, j};
            dis[i][j] = inf;
        }
    dis[src.first][src.second] = 0;
    bfs.push({'.', src});
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == '*')
                bfs.push({'*', {i, j}});
    while(!bfs.empty()){
        char type = bfs.front().first;
        pair<int, int> u = bfs.front().second;
        bfs.pop();
        if(type == '*'){
            for(int k = 0; k < 4; k++){
                int x = u.first + adjR[k], y = u.second + adjC[k];
                pair<int, int> v = {x, y};
                if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.' && v != dst)
                    g[x][y] = '*', bfs.push({'*', v});
            }
        }
        else if(g[u.first][u.second] == '.'){
            for(int k = 0; k < 4; k++){
                int x = u.first + adjR[k], y = u.second + adjC[k];
                pair<int, int> v = {x, y};
                if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.' && dis[x][y] == inf)
                    dis[x][y] = dis[u.first][u.second] + 1, bfs.push({'.', v});
            }
        }
    }
    if(dis[dst.first][dst.second] == inf)
        cout << "KAKTUS" << endl;
    else
        cout << dis[dst.first][dst.second] << endl;
}