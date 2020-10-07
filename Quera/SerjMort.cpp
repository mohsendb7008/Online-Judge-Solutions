#include <bits/stdc++.h>
using namespace std;

int n, k;
long long int a[103];
long long int ps[103];

long long int dp[103][103];

long long int cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == j)
        return dp[i][j] = 0;
    long long int ans = LONG_MAX;
    for(int z = i + 1; z <= j; z++){
        long long int value = cdp(i, z-1) + cdp(z, j) + ps[j];
        if(i > 0)
            value -= ps[i-1];
        ans = min(ans, value);
    }
    return dp[i][j] = ans;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    partial_sum(a, a + k, ps);
    for(int i = 0; i < 103; i++)
        for(int j = 0; j < 103; j++)
            dp[i][j] = -1;
    cout << cdp(0, k-1) << endl;
}