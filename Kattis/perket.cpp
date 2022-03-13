// Perket

#include <bits/stdc++.h>
using namespace std;

int n, s[13], b[13];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i] >> b[i];
  }
  int ans = INT_MAX;
  for(int mask = 1; mask < (1 << n); mask++){
    int total_s = 1;
    int total_b = 0;
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)){
        total_s *= s[i];
        total_b += b[i];
      }
    }
    ans = min(ans, abs(total_s - total_b));
  }
  cout << ans << endl;
}
