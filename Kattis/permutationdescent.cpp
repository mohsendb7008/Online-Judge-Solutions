#include <bits/stdc++.h>
using namespace std;

// Permutation Descent Counts

int P, i, n, k;

int dp[103][103];

int main(){
    dp[2][0] = dp[2][1] = 1;
    for(int i = 3; i <= 100; i++)
        for(int k = 0; k < i; k++)
            dp[i][k] = (((i - k) * dp[i-1][k-1]) % 1001113  + ((k + 1) * dp[i-1][k]) % 1001113) % 1001113;
    cin >> P;
    while(P--){
        cin >> i >> n >> k;
        cout << i << " " << dp[n][k] << endl;
    }
}