#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1000000007;

int n, k, d;
num dp[103][3];

int main(){
    cin >> n >> k >> d;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int c = 0; c < 2; c++)
            for(int j = 1; j <= min(i, k); j++)
                dp[i][c] = (dp[i][c] + dp[i-j][c ? (j >= d ? 0 : 1) : 0]) % mod;
    cout << dp[n][1] << endl; 
}