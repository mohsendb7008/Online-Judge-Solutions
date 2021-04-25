#include <bits/stdc++.h>
using namespace std;

// Speed Limit

int n, s[13], t[13];

int main(){
    while(1){
        cin >> n;
        if(n == -1)
            break;
        for(int i = 0; i < n; i++)
            cin >> s[i] >> t[i];
        int ans = s[0] * t[0];
        for(int i = 1; i < n; i++)
            ans += s[i] * (t[i] - t[i-1]);
        cout << ans << " miles\n";
    }
}