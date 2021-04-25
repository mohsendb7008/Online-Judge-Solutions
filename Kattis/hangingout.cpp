#include <bits/stdc++.h>
using namespace std;

// Hanging Out on the Terrace

int main(){
    int l, n, p = 0, ans = 0;
    cin >> l >> n;
    while(n--){
        string s;
        int x;
        cin >> s >> x;
        if(s == "leave")
            p -= x;
        else if(s == "enter"){
            if(p + x > l)
                ans++;
            else
                p += x;
        }
    }
    cout << ans << endl;
}