// The Plank

#include <bits/stdc++.h>
using namespace std;

int n;
long long int dp[30];

int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        if(i - 2 >= 0)
            dp[i] += dp[i-2];
        if(i - 3 >= 0)
            dp[i] += dp[i-3];
    }
    cout << dp[n] << endl;
}