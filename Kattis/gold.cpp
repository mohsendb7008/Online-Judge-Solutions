#include <bits/stdc++.h>
using namespace std;

// Getting Gold

int n, m;
char grid[53][53];
bool vis[53][53];

int adjR[4]{1, -1, 0, 0};
int adjC[4]{0, 0, -1, 1};
int adjRR[12]{1, 2, 1, -1, -2, -1, -1, 0, 1, -1, 0, 1};
int adjCC[12]{-1, 0, 1, -1, 0, 1, -1, -2, -1, 1, 2, 1};

int ans = 0;
void dfs(int i, int j){
    vis[i][j] = true;
    if(grid[i][j] == 'G')
        ans++;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if(grid[x][y] == '#' || vis[x][y])
            continue;
        bool trap = false;
        for(int z = 0; z < 3; z++){
            int xx = i + adjRR[3 * k + z], yy = j + adjCC[3 * k + z];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 'T'){
                trap = true;
                break;
            }
        }
        if(trap){
            if(grid[x][y] == 'G')
                ans++, grid[x][y] = '.';
            continue;
        }
        dfs(x, y);
    }
    
}

int main(){
    cin >> m >> n;
    int sx, sy;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> grid[i][j], vis[i][j] = false;
            if(grid[i][j] == 'P')
                sx = i, sy = j;
        }
    for(int k = 0; k < 4; k++){
        int x = sx + adjR[k], y = sy + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'T'){
            cout << 0 << endl;
            return 0;
        }
    }
    dfs(sx, sy);
    cout << ans << endl;
}