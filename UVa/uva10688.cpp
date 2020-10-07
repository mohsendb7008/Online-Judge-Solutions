#include <bits/stdc++.h>
using namespace std;

// The Poor Giant

int N, K;
int dp[503][503];

int cdp(int i, int j){
    if(j <= i)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k <= j; k++)
        ans = min(ans, (k + K)*(1 + (k-i) + (j-k)) + cdp(i, k-1) + cdp(k+1, j));
    return dp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> N >> K;
        for(int i = 0; i < 503; i++)
            for(int j = 0; j < 503; j++)
                dp[i][j] = -1;
        cout << "Case " << test << ": " << cdp(1, N) << endl;
    }
}