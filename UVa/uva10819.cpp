#include <bits/stdc++.h>
using namespace std;

// Trouble of 13-Dots

int m, n;
int p[103];
int f[103];

int dp[103][10203];

int main(){
    while(cin >> m >> n){
        for(int i = 1; i <= n; i++)
            cin >> p[i] >> f[i];
        dp[0][0] = 0;
        for(int j = 1; j <= m + 200; j++)
            dp[0][j] = -1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= m + 200; j++){
                dp[i][j] = dp[i-1][j];
                if(j - p[i] >= 0 && dp[i-1][j-p[i]] != -1)
                    dp[i][j] = max(dp[i][j], f[i] + dp[i-1][j-p[i]]);
            }
        int ans = -1;
        if(m <= 1800){
            for(int j = 0; j <= m; j++)
                ans = max(ans, dp[n][j]);
        }
        else if(m < 2001){
            for(int j = 0; j <= m; j++)
                ans = max(ans, dp[n][j]);
            for(int j = 2001; j <= m + 200; j++)
                ans = max(ans, dp[n][j]);
        }
        else{
            for(int j = 0; j <= m + 200; j++)
                ans = max(ans, dp[n][j]);
        }
        cout << ans << endl;
    }
}