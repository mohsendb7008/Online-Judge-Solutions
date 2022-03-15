#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    cin >> s;
    if(next_permutation(s.begin(), s.end())){
      cout << s << endl;
    }
    else{
      cout << "no answer" << endl;
    }
  }
}
