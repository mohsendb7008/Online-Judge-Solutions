#include <bits/stdc++.h>
using namespace std;'

// Exact Change

int c, n;
int coins[103];
int dp[1000003][103];

int inf = INT_MAX;

int cdp(int cost, int i){
    if(i == -1)
        return cost == 0 ? 0 : inf;
    if(dp[cost][i] != -1)
        return dp[cost][i];
    int ans = cdp(cost, i-1);
    if(cost >= coins[i]){
        int value = cdp(cost - coins[i], i-1);
        if(value != inf)
            ans = min(ans, 1 + value);
    }
    return dp[cost][i] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> c >> n;
        for(int i = 0; i < n; i++)
            cin >> coins[i];
            for(int i = 0; i < 1000003; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] = -1;
        while(true){
            int ans = cdp(c, n-1);
            if(ans != inf){
                cout << c << " " << ans << endl;
                break;
            }
            c++;
        }
    }
}