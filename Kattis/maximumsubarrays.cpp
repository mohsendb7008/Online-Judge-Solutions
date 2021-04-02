#include <bits/stdc++.h>
using namespace std;

// Maximum Subarrays

#define num long long int
int n, k;
num a[5003];
num dp[5003][5003];
num dp2[5003][5003];

int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n; i++)
        cin >> a[i];
    dp[1][1] = dp2[1][1] = a[1];
    for(int i = 2; i <= n; i++)
        for(int k = 1; k <= i; k++){
            dp[i][k] = a[i] + (k == 1 ? 0 : dp2[i-1][k-1]);
            if(k <= i-1)
                dp[i][k] = max(dp[i][k], a[i] + dp[i-1][k]);
            dp2[i][k] = dp[i][k];
            if(k <= i-1)
                dp2[i][k] = max(dp2[i][k], dp2[i-1][k]);
        } 
    cout << dp2[n][k] << endl;
}