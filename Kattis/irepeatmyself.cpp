// I Repeat Myself I Repeat Myself I Repeat

#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    getline(cin, s);
    for(int ans = 1; ans <= s.size(); ans++){
      bool ok = true;
      for(int i = 0; i < s.size(); i++){
        if(s[i] != s[i % ans]){
          ok = false;
          break;
        }
      }
      if(ok){
        cout << ans << endl;
        break;
      }
    }
  }
}
