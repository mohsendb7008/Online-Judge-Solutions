#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, dp[2003][2003];

int main(){
    cin >> s >> t;
    n = s.size(), m = t.size();
    for(int i = n; i >= 0; i--)
        for(int j = m; j >= 0; j--){
            if(i == n || j == m)
                dp[i][j] = 0;
            else if(s[i] == t[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    cout << dp[0][0] << endl;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s[i] == t[j])
            cout << s[i], i++, j++;
        else if(dp[i+1][j] > dp[i][j+1])
            i++;
        else
            j++;
    }
    cout << endl;
}