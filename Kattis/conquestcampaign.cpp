#include <bits/stdc++.h>
using namespace std;

// Conquest Campaign

const int inf = INT_MAX;

int r, c, dist[103][103], n, x, y;
queue<pair<int, int>> bfs;

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

int main(){
    cin >> r >> c >> n;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            dist[i][j] = inf;
    while(n--)
        cin >> x >> y, x--, y--, dist[x][y] = 1, bfs.push({x, y});
    while(!bfs.empty()){
        int i = bfs.front().first, j = bfs.front().second;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int x = i + adjR[k], y = j + adjC[k];
            if(x >= 0 && x < r && y >= 0 && y < c && dist[x][y] == inf)
                dist[x][y] = dist[i][j] + 1, bfs.push({x, y});
        }
    }
    int ans = 1;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            ans = max(ans, dist[i][j]);
    cout << ans << endl;
}