// Cinema Crowds

#include <bits/stdc++.h>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  int ans = 0;
  while(n--){
    int x;
    cin >> x;
    if(m >= x){
      m -= x;
    }
    else{
      ans++;
    }
  }
  cout << ans << endl;
}
