#include <bits/stdc++.h>
using namespace std;

// How do you add?

int dp[103][103];

int cdp(int n, int k){
    if(k == 1)
        return 1;
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = (ans + cdp(n-i, k-1)) % 1000000;
    return dp[n][k] = ans;
}

int main(){
    for(int i = 0; i < 103; i++)
        for(int j = 0; j < 103; j++)
            dp[i][j] = -1;
    int n, k;
    while(true){
        cin >> n >> k;
        if(n + k == 0)
            break;
        cout << cdp(n, k) << endl;
    }
}