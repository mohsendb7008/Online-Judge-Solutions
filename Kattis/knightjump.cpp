#include <bits/stdc++.h>
using namespace std;

// Knight Jump

#define inf -1

int adjR[8]{1, 2, 1, 2, -1, -2, -1, -2};
int adjC[8]{2, 1, -2, -1, 2, 1, -2, -1};

int n;
char g[103][103];
int dis[103][103];
queue<pair<int, int>> bfs;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            dis[i][j] = inf;
            if(g[i][j] == 'K')
                dis[i][j] = 0, bfs.push({i, j});
        }
    while(!bfs.empty()){
        pair<int, int> u = bfs.front();
        bfs.pop();
        for(int k = 0; k < 8; k++){
            int x = u.first + adjR[k], y = u.second + adjC[k];
            if(x >= 0 && x < n && y >= 0 && y < n && g[x][y] != '#' && dis[x][y] == inf)
                dis[x][y] = dis[u.first][u.second] + 1, bfs.push({x, y});
        }

    }
    cout << dis[0][0] << endl;
}