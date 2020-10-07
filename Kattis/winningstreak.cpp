#include <bits/stdc++.h>
using namespace std;

// Winning Streak

int n;
double p, ans;

double pp[3003];
double dp[3003][3003];

double cdp(int i, int s){
    if(dp[i][s] != -1)
        return dp[i][s];
    if(i == s)
        return dp[i][s] = 1;
    if(i == s + 1)
        return dp[i][s] = 1 - pp[i];
    return dp[i][s] = cdp(i-1, min(i-1, s)) - cdp(i-s-2, min(i-s-2, s)) * (1 - p) * pp[s+1];
}

int main(){
    cout << fixed << setprecision(10);
    while(cin >> n >> p){
        pp[0] = 1;
        for(int i = 1; i < 3003; i++)
            pp[i] = pp[i-1] * p;
        for(int i = 0; i < 3003; i++)
            for(int j = 0; j < 3003; j++)
                dp[i][j] = -1;
        ans = 0;
        for(int s = 1; s <= n; s++)
            ans += (cdp(n, s) - cdp(n, s-1)) * s;
        cout << ans << endl;
    }
}