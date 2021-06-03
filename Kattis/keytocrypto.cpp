#include <bits/stdc++.h>
using namespace std;

// The Key to Cryptography

string s, t;

int main(){
    cin >> s >> t;
    string ans = "";
    for(int i = 0; i < min(s.size(), t.size()); i++)
        ans.push_back((s[i]-t[i]+26)%26+'A');
    for(int i = t.size(); i < s.size(); i++)
        ans.push_back((s[i]-ans[i-t.size()]+26)%26+'A');
    cout << ans << endl;
}