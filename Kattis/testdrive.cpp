// Test Drive

#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int x = b - a, y = c - b;
  if(x * y < 0){
    cout << "turned" << endl;
    return 0;
  }
  x = abs(x), y = abs(y);
  if(x == y){
    cout << "cruised" << endl;
  }
  else if(x < y){
    cout << "accelerated" << endl;
  }
  else{
    cout << "braked" << endl;
  }
}
