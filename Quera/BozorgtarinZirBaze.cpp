#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 + 3;

int n;
num dp[maxn], ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dp[i];
    ans = dp[0];
    for(int i = 1; i < n; i++)
        dp[i] = max(dp[i], dp[i] + dp[i-1]), ans = max(ans, dp[i]);
    cout << ans << endl;
}