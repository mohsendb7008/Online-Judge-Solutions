// Roll Call

#include <bits/stdc++.h>
using namespace std;

set<pair<string, string>> s;
map<string, int> m;

int main(){
  string first, last;
  while(cin >> first >> last){
    s.insert({last, first});
    m[first]++;
  }
  for(auto it : s){
    if(m[it.second] == 1){
      cout << it.second << endl;
    }
    else{
      cout << it.second << " " << it.first << endl;
    }
  }
}
