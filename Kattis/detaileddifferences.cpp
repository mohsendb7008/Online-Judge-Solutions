#include <bits/stdc++.h>
using namespace std;

// Detailed Differences

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        cout << s << '\n' << t << '\n';
        for(int i = 0; i < s.size(); i++)
            cout << (s[i] == t[i] ? '.' : '*');
        cout << '\n' << '\n';
    }
}