#include <bits/stdc++.h>
using namespace std;

// Nikola

int n;
int a[1003];

int dp[1003][1003];

int cdp(int i, int p){
    if(i == n-1)
        return a[n-1];
    if(p > n)
        return INT_MAX;
    if(dp[i][p] != -1)
        return dp[i][p];
    int ans = INT_MAX;
    if(i + p < n){
        int subp = cdp(i+p, p+1);
        if(subp != INT_MAX)
            ans = min(ans, a[i] + subp);
    }
    int x = i - p + 1;
    int sum = a[i];
    while(x >= 0){
        int subp = cdp(x, p);
        if(subp != INT_MAX)
            ans = min(ans, sum + subp);
        sum += a[x];
        x -= p - 1;
    }
    return dp[i][p] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int p = 0; p <= n; p++)
            dp[i][p] = -1;
    cout << cdp(1, 2) << endl;
}