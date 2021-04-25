#include <bits/stdc++.h>
using namespace std;

// Sum Squared Digits Function

int main(){
    int t;
    cin >> t;
    while(t--){
        int k, b, n;
        cin >> k >> b >> n;
        long long int ans = 0;
        while(n)
            ans += (n % b) * (n % b), n /= b;
        cout << k << ' ' << ans << '\n';
    }
}