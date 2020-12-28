#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

const int maxn = 1e5 + 1;

int q, x;
num dp[maxn];

int main(){
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i < maxn; i++)
        dp[i] = (((dp[i-1] + dp[i-2]) % mod + dp[i-3]) % mod - dp[i-4] + mod) % mod;
    cin >> q;
    while(q--)
        cin >> x, cout << dp[x] << endl;
}