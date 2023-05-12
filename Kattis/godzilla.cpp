#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000003;

int n, m;
char g[1003][1003];

int adjR[4]{-1, 0, 1, 0};
int adjC[4]{0, 1, 0, -1};

int gx[MAX], gy[MAX], ruinedAt[1003][1003], visited[1003][1003], dis[1003][1003];
vector<pair<int, int>> residents, mechs;

set<pair<int, int>> destinations;

void judge(int guessTime){
  destinations.clear();
  int gxNow = gx[guessTime];
  int gyNow = gy[guessTime];
  destinations.insert({gxNow, gyNow});
  for(int i = gxNow - 1; i >= 0; i--){
    if(g[i][gyNow] == 'R' && ruinedAt[i][gyNow] > guessTime){
      break;
    }
    destinations.insert({i, gyNow});
  }
  for(int i = gxNow + 1; i < n; i++){
    if(g[i][gyNow] == 'R' && ruinedAt[i][gyNow] > guessTime){
      break;
    }
    destinations.insert({i, gyNow});
  }
  for(int j = gyNow - 1; j >= 0; j--){
    if(g[gxNow][j] == 'R' && ruinedAt[gxNow][j] > guessTime){
      break;
    }
    destinations.insert({gxNow, j});
  }
  for(int j = gyNow + 1; j < m; j++){
    if(g[gxNow][j] == 'R' && ruinedAt[gxNow][j] > guessTime){
      break;
    }
    destinations.insert({gxNow, j});
  }
}

int solve(){
  visited[gx[0]][gy[0]] = 1;
  int t = 0;
  while (true){
    t++;
    bool found = 0;
    for(int k = 0; k < 4; k++){
      int newX = gx[t-1] + adjR[k];
      int newY = gy[t-1] + adjC[k];
      if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && g[newX][newY] == 'R'){
        found = 1;
        gx[t] = newX;
        gy[t] = newY;
        visited[newX][newY] = 1;
        ruinedAt[newX][newY] = t;
        break;
      }
    }
    if(!found){
      for(int k = 0; k < 4; k++){
        int newX = gx[t-1] + adjR[k];
        int newY = gy[t-1] + adjC[k];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY]){
          found = 1;
          gx[t] = newX;
          gy[t] = newY;
          visited[newX][newY] = 1;
          break;
        }
      }
    }
    if(!found){
      t--;
      break;
    }
  }
  vector<pair<int, int>> bfs;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      dis[i][j] = INT_MAX;
    }
  }
  for(auto mech: mechs){
    dis[mech.first][mech.second] = 0;
    bfs.push_back(mech);
  }
  t = 0;
  while(!bfs.empty()){
    t++;
    vector<pair<int, int>> frontier;
    for(auto u: bfs){
      bool again = 0;
      for(int k = 0; k < 4; k++){
        int newX = u.first + adjR[k];
        int newY = u.second + adjC[k];
        if(newX >= 0 && newX < n && newY >= 0 && newY < m && dis[newX][newY] == INT_MAX){
          if(g[newX][newY] == 'R'){
            if (ruinedAt[newX][newY] <= t){
              dis[newX][newY] = dis[u.first][u.second] + 1;
              frontier.push_back({newX, newY});
            } else {
              again = 1;
            }
          } else {
            dis[newX][newY] = dis[u.first][u.second] + 1;
            frontier.push_back({newX, newY});
          }
        }
      }
      if (again) {
        frontier.push_back(u);
      }
    }
    bfs = frontier;
    judge(t);
    bool found = 0;
    for(auto it: destinations){
      if(dis[it.first][it.second] != INT_MAX){
        found = 1;
        break;
      }
    }
    if(found){
      break;
    }
  }
  int ans = 0;
  for(auto res: residents){
    if(ruinedAt[res.first][res.second] <= t){
      ans++;
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> m >> n;
    residents.clear();
    mechs.clear();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> g[i][j];
        if (g[i][j] == 'G'){
          gx[0] = i;
          gy[0] = j;
        }
        else if (g[i][j] == 'M'){
          mechs.push_back({i, j});
        }
        else if (g[i][j] == 'R'){
          residents.push_back({i, j});
          ruinedAt[i][j] = INT_MAX;
        }
        visited[i][j] = 0;
      }
    }
    cout << solve() << endl;
  }
}