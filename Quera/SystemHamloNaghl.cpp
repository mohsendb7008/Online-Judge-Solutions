#include <bits/stdc++.h>
using namespace std;

int m, n, max_p, max_w;
int dc[5003], w[5003], dp[5003];

int main(){
  cin >> m >> n >> max_p >> max_w;
  for(int i = 0; i < n; i++){
    cin >> dc[i] >> w[i];
  }
  for(int i = n-1; i >= 0; i--){
    int center = dc[i];
    int weight = w[i];
    int packages = 1;
    int changes = 1;
    dp[i] = 1 + dp[i+1];
    for(int j = i+1; j < n; j++){
      weight += w[j];
      packages++;
      if(weight > max_w || packages > max_p){
        break;
      }
      if(dc[j] != center){
        changes++;
      }
      center = dc[j];
      dp[i] = min(dp[i], changes + dp[j+1]);
    }
    dp[i] += 1;
  }
  cout << dp[0] << endl;
}
