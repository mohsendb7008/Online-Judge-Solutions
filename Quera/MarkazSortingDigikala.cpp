#include <bits/stdc++.h>
using namespace std;

int n, m, grid[503][503], vis[503][503];

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

int min_i, max_i, min_j, max_j;

void dfs(int x, int y){
  vis[x][y] = 1;
  min_i = min(min_i, x);
  max_i = max(max_i, x);
  min_j = min(min_j, y);
  max_j = max(max_j, y);
  for(int k = 0; k < 4; k++){
    int u = x + adjR[k];
    int v = y + adjC[k];
    if(u >= 0 && u < n && v >= 0 && v < m && grid[u][v] && !vis[u][v]){
      dfs(u, v);
    }
  }
}

int main(){
  int k;
  cin >> n >> m >> k;
  while(k--){
    int r, c1, c2;
    cin >> r >> c1 >> c2;
    for(int i = c1; i <= c2; i++){
      grid[r-1][i-1] = 1;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] && !vis[i][j]){
        min_i = min_j = INT_MAX;
        max_i = max_j = INT_MIN;
        dfs(i, j);
        ans = max(ans, (max_i - min_i + 1) * (max_j - min_j + 1));
      }
    }
  }
  cout << ans << endl;
}
