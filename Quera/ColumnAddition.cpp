#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int n, dp[1003][2];
string a, b, k;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        cin >> a >> b >> k;
        for(int i = 0; i <= n; i++)
            for(int c = 0; c < 2; c++){
                if(!i)
                    dp[i][c] = c ? inf : 0;
                else{
                    dp[i][c] = inf;
                    if(dp[i - 1][c] != inf)
                        dp[i][c] = min(dp[i][c], 1 + dp[i - 1][c]);
                    int s = a[i - 1] - '0' + b[i - 1] - '0' + c;
                    if(s % 10 == k[i - 1] - '0' && dp[i - 1][s / 10] != inf)
                        dp[i][c] = min(dp[i][c], dp[i - 1][s / 10]);
                }
            }
        cout << dp[n][0] << endl;
    }
}