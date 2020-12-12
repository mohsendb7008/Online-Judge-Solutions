#include <bits/stdc++.h>
using namespace std;

// Un Vare Ab

int w, s, c, k;

string solve() {
  if (s < k) 
    return "YES";
  if (w + c < k) 
    return "YES";
  if (w + c == k && s <= 2 * k) 
    return "YES";
  if (s == k && w + c <= 2 * k) 
    return "YES";
  return "NO";
}

int main() {
  cin >> w >> s >> c >> k;
  cout << solve() << endl;
  return 0;
}
