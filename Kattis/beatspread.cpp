// Beat the Spread!

#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int s, d;
    cin >> s >> d;
    if((s + d) % 2){
      cout << "impossible" << endl;
      continue;
    }
    int a = (s + d) / 2;
    int b = s - a;
    if(a >= 0 && b >= 0){
      cout << a << " " << b << endl;
    }
    else{
      cout << "impossible" << endl;
    }
  }
}
