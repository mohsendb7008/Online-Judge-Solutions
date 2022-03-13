// CPR Number

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int sum = 0;
  sum += 4 * (s[0] - '0');
  sum += 3 * (s[1] - '0');
  sum += 2 * (s[2] - '0');
  sum += 7 * (s[3] - '0');
  sum += 6 * (s[4] - '0');
  sum += 5 * (s[5] - '0');
  sum += 4 * (s[7] - '0');
  sum += 3 * (s[8] - '0');
  sum += 2 * (s[9] - '0');
  sum += 1 * (s[10] - '0');
  cout << ((sum % 11) ? "0" : "1") << endl;
}
