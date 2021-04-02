#include <bits/stdc++.h>
using namespace std;

// Islands

int n, m;
char grid[53][53];
bool vis[53][53];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};

void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'W' && !vis[x][y])
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
            if(grid[i][j] == 'L' && !vis[i][j])
                ans++, dfs(i, j);
    cout << ans << endl;
}