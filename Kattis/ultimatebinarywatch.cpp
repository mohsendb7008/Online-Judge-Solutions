// Ultimate Binary Watch

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < 4; i++){
      int j = 1 << (3 - i);
      cout << ((j & (s[0] - '0')) ? "*" : ".");
      cout << " ";
      cout << ((j & (s[1] - '0')) ? "*" : ".");
      cout << "   ";
      cout << ((j & (s[2] - '0')) ? "*" : ".");
      cout << " ";
      cout << ((j & (s[3] - '0')) ? "*" : ".");
      cout << endl;
    }
}
