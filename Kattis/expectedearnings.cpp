// Expected Earnings

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  double p;
  cin >> n >> k >> p;
  if(p * n >= k){
    cout << "spela inte!" << endl;
  }
  else{
    cout << "spela" << endl;
  }
}
