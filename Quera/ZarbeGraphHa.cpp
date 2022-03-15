#include <bits/stdc++.h>

using namespace std;

const int MAXN = 503;
const int MAXK = 500003;

int n, m, k, floyd[MAXN][MAXN];
pair<int, int> path[MAXK];

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      floyd[i][j] = INT_MAX;
    }
  }
  while(m--){
    int u, v;
    cin >> u >> v;
    u--, v--;
    floyd[u][v] = floyd[v][u] = 1;
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX){
          floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
        }
      }
    }
  }
  cin >> k;
  for(int i = 0; i < k; i++){
    cin >> path[i].first;
    path[i].first--;
  }
  for(int i = 0; i < k; i++){
    cin >> path[i].second;
    path[i].second--;
  }
  int ans = 0;
  for(int i = 0; i < k; i++){
    if(path[i].first == path[i].second){
      continue;
    }
    if(floyd[path[i].first][path[i].second] == INT_MAX){
      cout << -1 << endl;
      return 0;
    }
    ans += floyd[path[i].first][path[i].second];
  }
  cout << ans << endl;
}

