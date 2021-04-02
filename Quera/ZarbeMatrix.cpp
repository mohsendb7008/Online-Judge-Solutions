#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, a[303];
num dp[303][303];

num cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == j)
        return dp[i][j] = 0;
    num ans = LLONG_MAX;
    for(int k = i; k < j; k++)
        ans = min(ans, cdp(i, k) + cdp(k+1, j) + a[i] * a[k+1] * a[j+1]);
    return dp[i][j] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n + 1; i++)
        cin >> a[i];
    for(int i = 0; i < 303; i++)
        for(int j = 0; j < 303; j++)
            dp[i][j] = -1;
    cout << cdp(0, n-1) << endl;
}