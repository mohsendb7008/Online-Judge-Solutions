#include <bits/stdc++.h>
using namespace std;

// Frogger

const int inf = INT_MAX;

int x, n, m, dis[25][53][53];
char g[25][53];

queue<pair<int, pair<int, int>>>  bfs;

int adjR[5]{0, 0, -1, 1, 0};
int adjC[5]{1, -1, 0, 0, 0};

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> x >> n >> m;
        for(int i = 0; i < n + 2; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        for(int i = 0; i < n + 2; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < m; k++)
                    dis[i][j][k] = inf;
        for(int j = 0; j < m; j++)
            if(g[n + 1][j] == 'F'){
                dis[n + 1][j][0] = 0, bfs.push({0, {n + 1, j}});
                break;
            }
        while(!bfs.empty()){
            int p = bfs.front().first;
            int i = bfs.front().second.first, j = bfs.front().second.second;
            bfs.pop();
            if(dis[i][j][p] == x)
                continue;
            for(int k = 0; k < 5; k++){
                int x = i + adjR[k], y = j + adjC[k];
                if(x >= 0 && x < n + 2 && y >= 0 && y < m && dis[x][y][(p + 1) % m] == inf){
                    int row = ((n + 1 - x) % 2) ? -1 : 1;
                    if(g[x][(y + row * ((p + 1) % m) + m) % m] != 'X')
                        dis[x][y][(p + 1) % m] = dis[i][j][p] + 1, bfs.push({(p + 1) % m, {x, y}});
                }
            }
        }
        for(int j = 0; j < m; j++)
            if(g[0][j] == 'G'){
                int ans = inf;
                for(int k = 0; k < m; k++)
                    ans = min(ans, dis[0][j][k]);
                if(ans == inf)
                    cout << "The problem has no solution." << endl;
                else
                    cout << "The minimum number of turns is " << ans <<"." << endl;
                break;
            }
    }
}