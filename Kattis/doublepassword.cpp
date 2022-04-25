#include <bits/stdc++.h>
using namespace std;

// Double Password

int main(){
    string s, t;
    cin >> s >> t;
    int ans = 1;
    for(int i = 0; i < 4; i++){
        if(s[i] != t[i]){
            ans *= 2;
        }
    }
    cout << ans << endl;
}