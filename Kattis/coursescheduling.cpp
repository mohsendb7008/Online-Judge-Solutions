// Course Scheduling

#include <bits/stdc++.h>
using namespace std;

map<string, set<pair<string, string>>> m;

int main(){
  int n;
  cin >> n;
  while(n--){
    string a, b, c;
    cin >> a >> b >> c;
    m[c].insert({a, b});
  }
  for(auto it : m){
    cout << it.first << " " << (it.second).size() << endl;
  }
}
