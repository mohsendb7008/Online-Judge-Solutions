#include <bits/stdc++.h>
using namespace std;

int n, dp[503][503];
string s;

int cdp(int i, int j){
    if(j <= i)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = (s[i] != s[j]) + cdp(i + 1, j - 1);
    for(int k = i; k < j; k++)
        ans = min(ans, 1 + cdp(i, k) + cdp(k + 1, j));
    return dp[i][j] = ans;
}

int main(){
    cin >> s, n = s.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    cout << 1 + cdp(0, n - 1) << endl;
}