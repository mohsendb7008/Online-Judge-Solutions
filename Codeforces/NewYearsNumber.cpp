#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;

bool dp[maxn];

int main(){
    dp[2020] = dp[2021] = 1;
    for(int n = 2022; n < maxn; n++)
        dp[n] = dp[n - 2020] || dp[n - 2021];
    int t, n;
    cin >> t;
    while(t--)
        cin >> n, cout << (dp[n] ? "YES" : "NO") << endl;
}