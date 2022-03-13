// Metaprogramming

#include <bits/stdc++.h>
using namespace std;

map<string, int> dict;

int main(){
  string cmd;
  while(cin >> cmd){
    if(cmd == "define"){
      int i;
      string x;
      cin >> i >> x;
      dict[x] = i;
    }
    else if(cmd == "eval"){
      string x, y, z;
      cin >> x >> y >> z;
      auto i = dict.find(x);
      auto j = dict.find(z);
      if(i == dict.end() || j == dict.end()){
        cout << "undefined" << endl;
      }
      else{
        if(y == ">"){
          cout << ((i->second > j->second) ? "true" : "false") << endl;
        }
        else if(y == "<"){
          cout << ((i->second < j->second) ? "true" : "false") << endl;
        }
        else if(y == "="){
          cout << ((i->second == j->second) ? "true" : "false") << endl;
        }
      }
    }
  }
}
