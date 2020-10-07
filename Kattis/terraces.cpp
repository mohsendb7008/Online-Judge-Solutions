#include <bits/stdc++.h>
using namespace std;

// Terraces

int n, m;
int grid[503][503];
bool vis[503][503];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

bool possible;
int cnt;
void dfs(int i, int j){
    vis[i][j] = true;
    cnt++;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            if(grid[x][y] < grid[i][j])
                possible = false;
            if(grid[x][y] == grid[i][j] && !vis[x][y])
                dfs(x, y);
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], vis[i][j] = false;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j]){
                possible = true, cnt = 0;
                dfs(i, j);
                if(possible)
                    ans += cnt;
            }
    cout << ans << endl;
}