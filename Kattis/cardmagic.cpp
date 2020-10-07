#include <bits/stdc++.h>
using namespace std;

// Card Magic

const int mod = 1000000009;
int n, k, t;
long long int dp[103][5003];

int main(){
    cin >> n >> k >> t;
    dp[n][0] = 1;
    for(int i = n-1; i >= 0; i--)
        for(int j = 0; j <= t; j++)
            for(int c = 1; c <= min(k, j); c++)
                dp[i][j] += dp[i+1][j-c], dp[i][j] %= mod;
    cout << dp[0][t] << endl;
}