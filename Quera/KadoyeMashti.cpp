#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 100000;
const num mod = 1e9 + 7;

int t, k, a, b;
num dp[maxn + 3], ps[maxn + 3];

int main(){
    cin >> t >> k;
    dp[0] = 1;
    for(int i = 1; i <= maxn; i++)
        dp[i] = (dp[i-1] + (i >= k ? dp[i-k] : 0)) % mod;
    ps[1] = dp[1];
    for(int i = 2; i <= maxn; i++)
        ps[i] = (ps[i-1] + dp[i]) % mod;
    while(t--)
        cin >> a >> b, cout << (ps[b] - ps[a-1] + mod) % mod << endl;
}