// Eye of Sauron

#include <bits/stdc++.h>
using namespace std;

string s, o = "(", e = ")";

int main(){
    cin >> s;
    int i = find_first_of(s.begin(), s.end(), o.begin(), o.end()) - s.begin();
    reverse(s.begin(), s.end());
    int j = find_first_of(s.begin(), s.end(), e.begin(), e.end()) - s.begin();
    cout << ((i == j) ? "correct" : "fix") << endl;
}