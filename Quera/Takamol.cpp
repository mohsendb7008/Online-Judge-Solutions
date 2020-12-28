#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, dp[2003][2003];

int main(){
    cin >> s >> t, n = s.size(), m = t.size();
    for(int i = n; i >= 0; i--)
        for(int j = m; j >= 0; j--){
            if(i == n && j == m)
                dp[i][j] = 0;
            else if(i == n)
                dp[i][j] = 1 + dp[i][j+1];
            else if(j == m)
                dp[i][j] = 1 + dp[i+1][j];
            else if(s[i] == t[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = 1 + min(dp[i][j+1], dp[i+1][j]);
        }
    cout << dp[0][0] << endl;
}