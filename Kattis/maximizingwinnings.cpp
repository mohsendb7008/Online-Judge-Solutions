#include <bits/stdc++.h>
using namespace std;

// Maximizing (And Minimizing) Your Winnings

int n, m, r[53][53], dp[53][5003];

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> r[i][j];
        cin >> m;
        for(int t = 0; t <= m; t++)
            for(int i = 0; i < n; i++){
                if(t){
                    dp[i][t] = INT_MIN;
                    for(int j = 0; j < n; j++)
                        dp[i][t] = max(dp[i][t], dp[j][t-1] + r[i][j]);
                }
                else
                    dp[i][t] = 0;
            }
        cout << dp[0][m] << " ";
        for(int t = 0; t <= m; t++)
            for(int i = 0; i < n; i++){
                if(t){
                    dp[i][t] = INT_MAX;
                    for(int j = 0; j < n; j++)
                        dp[i][t] = min(dp[i][t], dp[j][t-1] + r[i][j]);
                }
                else
                    dp[i][t] = 0;
            }
        cout << dp[0][m] << endl;
    }
}