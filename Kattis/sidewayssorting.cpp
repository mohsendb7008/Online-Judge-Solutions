// Sideways Sorting

#include <bits/stdc++.h>
using namespace std;

int r, c;
char g[20][20];
vector<string> columns;

bool compare(const string& s, const string& t){
    for(int i = 0; i < s.size(); i++){
        if(tolower(s[i]) < tolower(t[i])){
            return true;
        }
        else if(tolower(s[i]) > tolower(t[i])){
            return false;
        }
    }
    return false;
}

int main(){
  while(1){
      cin >> r >> c;
      if(!(r + c)){
          break;
      }
      for(int i = 0; i < r; i++){
          for(int j = 0; j < c; j++){
              cin >> g[i][j];
          }
      }
      columns.clear();
      for(int j = 0; j < c; j++){
          string s;
          for(int i = 0; i < r; i++){
              s.push_back(g[i][j]);
          }
          columns.push_back(s);
      }
      stable_sort(columns.begin(), columns.end(), compare);
      for(int j = 0; j < c; j++){
          for(int i = 0; i < r; i++){
              g[i][j] = columns[j][i];
          }
      }
      for(int i = 0; i < r; i++){
          for(int j = 0; j < c; j++){
              cout << g[i][j];
          }
          cout << endl;
      }
      cout << endl;
  }
}