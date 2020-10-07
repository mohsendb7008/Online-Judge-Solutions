#include <bits/stdc++.h>
using namespace std;

// Sheba's Amoebas

int n, m;
char grid[103][103];
bool vis[103][103];

int adjR[8]{0, 0, 1, -1, 1, -1, 1, -1};
int adjC[8]{1, -1, 0, 0, 1, -1, -1, 1};

void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 8; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '#' && !vis[x][y])
            dfs(x, y);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], vis[i][j] = false;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == '#' && !vis[i][j])
                ans++, dfs(i, j);
    cout << ans << endl;
}