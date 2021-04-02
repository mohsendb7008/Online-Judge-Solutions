#include <bits/stdc++.h>
using namespace std;

#define num long long int

num s, x, k, dp[43][3], a[4]{0, 0, 1, 1}, b[4]{0, 1, 0, 1};

int main(){
    cin >> s >> x;
    if(x > s){
        cout << 0 << endl;
        return 0;
    }
    for(num i = 0; i <= 40; i++)
        if(s & (1ll << i))
            k = i;
    dp[k+1][0] = 1;
    for(num i = k; i >= 0; i--)
        for(num c = 0; c < 2; c++)
            for(num j = 0; j < 4; j++){
                num si = 0, xi = 0;
                if(s & (1ll << i))
                    si = 1;
                if(x & (1ll << i))
                    xi = 1;
                if((a[j] + b[j] + c) % 2 == si && (a[j] ^ b[j]) == xi)
                    dp[i][c] += dp[i+1][(a[j] + b[j] + c) / 2];
            }
    cout << dp[0][0] - 2 * (s == x) << endl;
}