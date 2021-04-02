#include <bits/stdc++.h>
using namespace std;

// Cheating Luck

int all;

int dp[2003][53][53];
int bet[2003][53][53];

int cdp(int d, int n, int k){
    if(dp[d][n][k] != -1)
        return dp[d][n][k];
    if(!d || !n)
        return dp[d][n][k] = d;
    int g = all - d;
    int ans = d;
    int lo = 0, hi = min(d, g);
    if(d)
        cdp(d-1, n, k), lo = bet[d-1][n][k];
    if(lo > hi)
        lo = hi;
    for(int pot = lo; pot <= hi; pot++){
        int subp = cdp(d + pot, n-1, k-1);
        if(n > k)
            subp = min(subp, cdp(d - pot, n-1, k));
        if(subp < ans)
            break;
        ans = subp, bet[d][n][k] = pot;
    }
    return dp[d][n][k] = ans;
}

int main(){
    for(int i = 0; i < 2003; i++)
        for(int j = 0; j < 53; j++)
            for(int k = 0; k < 53; k++)
                dp[i][j][k] = -1;
    int d, g, n, k;
    cin >> d >> g >> n >> k;
    all = d + g;
    cout << cdp(d, n, k) << endl;
}