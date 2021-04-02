#include <bits/stdc++.h>
using namespace std;

// A Grouping Problem

#define num unsigned long long int

num dp[1003][1003];
num a[1003];

int main(){
    int n, m;
    while(1){
        cin >> n >> m;
        if(n + m == 0)
            break;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        dp[0][0] = 1;
        dp[0][1] = a[0];
        for(int i = 1; i < n; i++)
            for(int k = 0; k <= i + 1; k++){
                if(k == 0)
                    dp[i][k] = 1;
                else
                    dp[i][k] = ((dp[i-1][k-1] * a[i]) % m + dp[i-1][k]) % m;
            }
        num ans = dp[n-1][0];
        for(int i = 1; i <= n; i++)
            ans = max(ans, dp[n-1][i]);
        cout << ans << endl;
    }

}