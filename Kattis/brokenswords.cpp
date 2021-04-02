#include <bits/stdc++.h>
using namespace std;

// Broken Swords

int n;
string s;

int main(){
    int tb = 0, lr = 0;
    cin >> n;
    while(n--){
        cin >> s;
        if(s[0] == '0')
            tb++;
        if(s[1] == '0')
            tb++;
        if(s[2] == '0')
            lr++;
        if(s[3] == '0')
            lr++;
    }
    int ans = min(tb, lr) / 2;
    cout << ans << " " << tb - 2 * ans << " " << lr - 2 * ans << endl;
}