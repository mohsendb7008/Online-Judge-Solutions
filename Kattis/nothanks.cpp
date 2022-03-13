// No Thanks!

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  long long int ans = v[0];
  for(int i = 1; i < n; i++){
    if(v[i-1] != v[i] - 1){
      ans += v[i];
    }
  }
  cout << ans << endl;
}
