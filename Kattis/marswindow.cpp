// Mars Window

#include <bits/stdc++.h>
using namespace std;

set<int> years;

int main(){
  int y = 2018;
  int m = 3;
  years.insert(y);
  while(y <= 10000){
    m += 26;
    y += m / 12;
    m %= 12;
    years.insert(y);
  }
  int n;
  cin >> n;
  cout << ((years.find(n) != years.end()) ? "yes" : "no") << endl;
}
