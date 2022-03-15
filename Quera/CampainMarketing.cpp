#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, a[maxn];
set<int> other, other2;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    other.clear();
    other2.clear();
    cin >> n;
    for(int i = 1; i <= 2 * n; i++){
      other.insert(i);
      other2.insert(i);
    }
    for(int i = 0; i < n; i++){
      cin >> a[i];
      other.erase(a[i]);
      other2.erase(a[i]);
    }
    int ans_upper = 0;
    for(int i = 0; i < n; i++){
      auto it = other.upper_bound(a[i]);
      if(it == other.end()){
        break;
      }
      other.erase(it);
      ans_upper++;
    }
    int ans_lower = n;
    for(int i = n-1; i >= 0; i--){
      auto it = other2.upper_bound(a[i]);
      if(it == other2.begin()){
        break;
      }
      other2.erase(prev(it));
      ans_lower--;
    }
    cout << max(ans_upper - ans_lower + 1, 0) << endl;
  }
}
