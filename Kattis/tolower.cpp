#include <bits/stdc++.h>
using namespace std;

// ToLower

int p, t;
string s;

int main(){
    cin >> p >> t;
    int ans = 0;
    for(int i = 0; i < p; i++){
        int acc = 1;
        for(int i = 0 ; i < t; i++){
            cin >> s;
            for(int i = 1; i < s.size(); i++)
                if(s[i] >= 'A' && s[i] <= 'Z')
                    acc = 0;
        }
        ans += acc;
    }
    cout << ans << endl;
}