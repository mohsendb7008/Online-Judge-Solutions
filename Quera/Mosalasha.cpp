#include <bits/stdc++.h>
using namespace std;

int t, n, dp[103][103];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(!n){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                cin >> dp[i][j];
        for(int i = n-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        cout << dp[0][0] << endl;
    }
}