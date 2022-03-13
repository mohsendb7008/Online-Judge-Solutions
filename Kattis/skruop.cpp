// Turn It Up!

#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans = 7;
  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    string line;
    getline(cin, line);
    if(line == "Skru op!"){
      ans = min(ans + 1, 10);
    }
    else if(line == "Skru ned!"){
      ans = max(ans - 1, 0);
    }
  }
  cout << ans << endl;
}
