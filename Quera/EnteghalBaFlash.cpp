#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18;

int n, C, v[MAXN + 3], sum[(1 << MAXN) + 3], dp[(1 << MAXN) + 3];

int main()
{
  cin >> n >> C;
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  for(int mask = 1; mask < (1 << n); mask++){
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)){
        sum[mask] += v[i];
      }
    }
  }
  for(int mask = 1; mask < (1 << n); mask++){
    dp[mask] = INT_MAX;
    int sub = mask;
    while(sub){
      if(sum[sub] <= C){
        dp[mask] = min(dp[mask], 1 + dp[mask - sub]);
      }
      sub--;
      sub &= mask;
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}

