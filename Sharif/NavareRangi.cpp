#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 3;

int n, k, dp[maxn][26 + 3];
string s;

int main(){
    cin >> n >> k >> s;
    for(int c = 0; c < k; c++)
        dp[n][c] = 0;
    for(int i = n-1; i > 0; i--)
        for(int c = 0; c < k; c++){
            dp[i][c] = INT_MAX;
            for(int x = 0; x < k; x++)
                if(x != c)
                    dp[i][c] = min(dp[i][c], dp[i+1][x] + (x != s[i] - 'A'));
        }
    int ans = INT_MAX;
    for(int c = 0; c < k; c++)
        ans = min(ans, dp[1][c] + (c != s[0] - 'A'));
    cout << ans << endl;
}