#include <bits/stdc++.h>
using namespace std;

int n, t;
double p, dp[2003][2003];

int main(){
    cin >> n >> p >> t;
    for(int i = t; i >= 0; i--)
        for(int j = 0; j <= n; j++){
            if(i == t || j == n)
                dp[i][j] = j;
            else
                dp[i][j] = p * dp[i+1][j+1] + (1-p) * dp[i+1][j];
        }
    cout << fixed << setprecision(10) << dp[0][0] << endl;
}