#include <bits/stdc++.h>
using namespace std;

// The Mailbox Manufacturers Problem

int dp[103][103][13];

int cdp(int m1, int m2, int k){
    if(m1 > m2)
        return 0;
    if(dp[m1][m2][k] != -1)
        return dp[m1][m2][k];
    int ans = ((m2)*(m2+1)) / 2 - ((m1-1)*(m1)) / 2;
    if(k == 1)
        return dp[m1][m2][k] = ans;
    for(int x = m1; x <= m2; x++)
        ans = min(ans, x + max(cdp(m1, x-1, k-1), cdp(x+1, m2, k)));
    return dp[m1][m2][k] = ans;
}

int main(){
    for(int i = 0; i < 103; i++)
        for(int j = 0; j < 103; j++)
            for(int k = 0; k < 13; k++)
                dp[i][j][k] = -1;
    int n;
    cin >> n;
    while(n--){
        int k, m;
        cin >> k >> m;
        cout << cdp(1, m, k) << endl;
    }
}