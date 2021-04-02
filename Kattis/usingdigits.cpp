#include <bits/stdc++.h>
using namespace std;

// Using Digits

int n, m, dp[103][103][53];
string code;
char grid[103][103];

int main(){
    cin >> m >> n >> code;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    for(int i = 0; i < n; i++)
        for(int j = m-1; j >= 0; j--)
            for(int k = code.size(); k >= 0; k--){
                if(!i && j == m-1){
                    dp[i][j][k] = grid[i][j]-'0';
                    continue;
                }
                dp[i][j][k] = INT_MAX;
                if(j < m-1){
                    dp[i][j][k] = min(dp[i][j][k], grid[i][j]-'0' + dp[i][j+1][k]);
                    if(k < code.size() && j+1+code[k]-'0' < m)
                        dp[i][j][k] = min(dp[i][j][k], grid[i][j]-'0' + dp[i][j+1+code[k]-'0'][k+1]);
                }
                if(i){
                    dp[i][j][k] = min(dp[i][j][k], grid[i][j]-'0' + dp[i-1][j][k]);
                    if(k < code.size() && i-1-code[k]+'0' >= 0)
                        dp[i][j][k] = min(dp[i][j][k], grid[i][j]-'0' + dp[i-1-code[k]+'0'][j][k+1]);
                }
            }
    cout << dp[n-1][0][0] << endl;
}