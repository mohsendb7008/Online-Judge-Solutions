#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m;
num grid[2003][2003], dp[2003][2003];

// Alternative way: dp[i][j][dir = 0 or 1] which dir indicates going left or right 

inline void right_down(){
    dp[0][0] = min(dp[0][0], grid[0][0]);
    for(int j = 1; j < m; j++)
        dp[0][j] = min(dp[0][j], dp[0][j-1] + grid[0][j]);
    for(int i = 1; i < n; i++)
        dp[i][0] = min(dp[i][0], dp[i-1][0] + grid[i][0]);
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1]) + grid[i][j]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], dp[i][j] = LONG_LONG_MAX;
    right_down();
    for(int j = m-2; j >= 0; j--)
        for(int i = 0; i < n; i++)
            dp[i][j] = min(dp[i][j], dp[i][j+1] + grid[i][j]);
    right_down();
    cout << dp[n-1][m-1] << endl;
}