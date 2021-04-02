#include <bits/stdc++.h>
using namespace std;

// Mountain Scenes

int n, w, h;
long long int dp[103][10003];

const int mod = 1e9 + 7;

int main(){
    cin >> n >> w >> h;
    for(int i = 0; i <= n; i++)
        dp[w][i] = 1;
    for(int i = w-1; i >= 0; i--)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= min(h, j); k++)
                dp[i][j] += dp[i+1][j-k], dp[i][j] %= mod;
    long long int ans = dp[0][n];
    ans += mod, ans -= min(h, n / w) + 1, ans %= mod;
    cout << ans << endl;
}