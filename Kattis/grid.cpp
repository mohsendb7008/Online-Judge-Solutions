#include <bits/stdc++.h>
using namespace std;

// Grid

const int inf = INT_MAX;

int n, m, dist[503][503];
char g[503][503];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

queue<pair<int, int>> bfs;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j], dist[i][j] = inf;
    dist[0][0] = 0, bfs.push({0, 0});
    while(!bfs.empty()){
        int i = bfs.front().first, j = bfs.front().second;
        bfs.pop();
        if(g[i][j] == '0')
            continue;
        for(int k = 0; k < 4; k++){
            int x = i + (g[i][j] - '0') * adjR[k], y = j + (g[i][j] - '0') * adjC[k];
            if(x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == inf)
                dist[x][y] = dist[i][j] + 1 ,bfs.push({x, y});
        }
    }
    cout << ((dist[n-1][m-1] == inf) ? -1 : dist[n-1][m-1]) << endl; 
}