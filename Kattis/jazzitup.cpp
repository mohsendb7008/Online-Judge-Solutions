// Jazz it Up!

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int not_prime[maxn];

int main(){
  int n;
  cin >> n;
  for(int m = 2; m < n; m++){
    if(!not_prime[m]){
      if(n % m){
        cout << m << endl;
        return 0;
      }
      for(int k = 2 * m; k < n; k += m){
        not_prime[k] = true;
      }
    }
  }
}
