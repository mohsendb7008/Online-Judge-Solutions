#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
num dp[33];

int main(){
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 0) + (i >= 5 ? dp[i-5] : 0);
    cout << dp[n] << endl;
}