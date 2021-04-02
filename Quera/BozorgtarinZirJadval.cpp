#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m;
num grid[503][503], psum[503][503], dp[503];

int main(){
    cin >> n >> m;
    for(int j = 0; j < m; j++)
        cin >> grid[0][j], psum[0][j] = grid[0][j];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], psum[i][j] = psum[i - 1][j] + grid[i][j];
    num ans = LLONG_MIN;
    for(int up = 0; up < n; up++)
        for(int down = up; down < n; down++)
            for(int i = 0; i < m; i++){
                num compress = psum[down][i] - (up ? psum[up - 1][i] : 0);
                if(i)
                    dp[i] = max(dp[i - 1] + compress, compress);
                else
                    dp[i] = compress;
                ans = max(ans, dp[i]);
            }
    cout << ans << endl;
}