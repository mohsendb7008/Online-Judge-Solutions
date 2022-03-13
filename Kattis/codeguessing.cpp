// Code Guessing

#include <bits/stdc++.h>
using namespace std;

int p, q, arr[6];
string s;
vector<int> a, b;

int main(){
  cin >> p >> q;
  cin >> s;
  arr[0] = 0;
  arr[5] = 10;
  for(int i = 0; i < 4; i++){
    if(s[i] == 'A'){
      a.push_back(i + 1);
    }
    else if(s[i] == 'B'){
      b.push_back(i + 1);
    }
  }
  arr[a[0]] = p;
  arr[a[1]] = q;
  if(b[0] == b[1] -1){
    if(arr[b[0] - 1] == arr[b[1] + 1] - 3){
      cout << arr[b[0] - 1] + 1 << " " << arr[b[1] + 1] - 1 << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  else{
    int u = -1;
    if(arr[b[0] - 1] == arr[b[0] + 1] - 2){
      u = arr[b[0] - 1] + 1;
    }
    int v = -1;
    if(arr[b[1] - 1] == arr[b[1] + 1] - 2){
      v = arr[b[1] + 1] - 1;
    }
    if(u != -1 && v != -1){
      cout << u << " " << v << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
}
