#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

const long long int inf = LONG_LONG_MAX;

int n, m;
vector<pair<int, int>> adj[maxn];

long long int sp[maxn][53];
priority_queue<pair<long long int, pair<int, int>>, vector<pair<long long int, pair<int, int>>>, greater<pair<long long int, pair<int, int>>>> dij;

int main(){
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for(int i = 0; i < n; i++){
    for(int w = 0; w <= 50; w++){
      sp[i][w] = inf;
    }
  }
  sp[0][0] = 0;
  dij.push({0, {0, 0}});
  while(!dij.empty()){
    long long int w = dij.top().first;
    int u = dij.top().second.first;
    int c = dij.top().second.second;
    dij.pop();
    if(sp[u][c] < w){
      continue;
    }
    for(auto it : adj[u]){
      int v = it.first;
      int d = it.second;
      if(c){
        int cost = (c + d) * (c + d);
        if(w + cost < sp[v][0]){
          sp[v][0] = w + cost;
          dij.push({sp[v][0], {v, 0}});
        }
      }
      else{
        if(w < sp[v][d]){
          sp[v][d] = w;
          dij.push({sp[v][d], {v, d}});
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(sp[i][0] == inf){
      cout << -1 << " ";
    }
    else{
      cout << sp[i][0] << " ";
    }
  }
  cout << endl;
}
