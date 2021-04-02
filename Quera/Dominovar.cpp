#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

int n;
num dp[10003];

int main(){
    cin >> n;
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    cout << dp[n] << endl;
}