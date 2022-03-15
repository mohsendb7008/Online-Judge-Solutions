#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> shops[53];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> shops[i].first >> shops[i].second;
  }
  int x, y;
  cin >> x >> y;
  for(int z = x; z <= y; z++){
    bool ok = false;
    for(int i = 0; i < n; i++)
      if(z >= shops[i].first && z <= shops[i].second){
        ok = true;
        break;
      }
    if(!ok){
      cout << "false" << endl;
      return 0;
    }
  }
  cout << "true" << endl;
}
