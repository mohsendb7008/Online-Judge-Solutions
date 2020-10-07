#include <bits/stdc++.h>
using namespace std;

// Ocean's Anti-11

const int mod = 1e9+7;
int dp[10003];

int main(){
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= 10000; i++)
        dp[i] = (dp[i-2] + dp[i-1]) % mod;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << endl;
    }
}