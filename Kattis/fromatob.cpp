// From A to B

#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while(a > b){
    if(a % 2){
      a++;
      ans++;
    }
    a /= 2;
    ans++;
  }
  ans += b - a;
  cout << ans << endl;
}
