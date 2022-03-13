// Height Ordering

#include <bits/stdc++.h>
using namespace std;

int a[23];

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int k;
    cin >> k;
    for(int i = 0; i < 20; i++){
      cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < 20; i++){
      for(int j = i + 1; j < 20; j++){
        if(a[i] > a[j]){
          ans++;
        }
      }
    }
    cout << k << " " << ans << endl;
  }
}
