#include <bits/stdc++.h>
using namespace std;

// Server

int n, t, a, s = 0, ans = 0;

int main(){
    cin >> n >> t;
    while(n--){
        cin >> a;
        if(s + a > t)
            break;
        s += a, ans++;
    }
    cout << ans << endl;
}