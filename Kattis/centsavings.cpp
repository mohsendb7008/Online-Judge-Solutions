#include <bits/stdc++.h>
using namespace std;

// Cent Savings

int n, d;
int p[2003];
int psum[2003];

inline int round(int x){
    if(x % 10 < 5)
        return (x / 10) * 10;
    return (x / 10 + 1) * 10; 
}

int dp[2003][23];

int inf = INT_MAX;

int cdp(int i, int d){
    if(dp[i][d] != -1)
        return dp[i][d];
    int ans = round(psum[i]);
    if(d > 0) for(int j = 1; j <= i; j++){
        int subp = cdp(j-1, d-1);
        ans = min(ans, subp + round(psum[i] - psum[j-1]));
    }
    return dp[i][d] = ans;
}

int main(){
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    partial_sum(p, p+n, psum);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= d; j++)
            dp[i][j] = -1;
    cout << cdp(n-1, d) << endl;
}