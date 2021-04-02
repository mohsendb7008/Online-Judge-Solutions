#include <bits/stdc++.h>
using namespace std;

// e-Coins

#define inf INT_MAX

int m, S;
pair<int, int> coins[43];

int dp[303][303];

int cdp(int iv, int cv){
    if(dp[iv][cv] != -1)
        return dp[iv][cv];
    if(iv + cv == 0)
        return dp[iv][cv] = 0;
    int ans = inf;
    for(int i = 0; i < m; i++){
        pair<int, int> coin = coins[i];
        if(coin.first <= iv && coin.second <= cv){
            int subp = cdp(iv - coin.first, cv - coin.second);
            if(subp != inf)
                ans = min(ans, 1 + subp);
        }
    }
    return dp[iv][cv] = ans;
}   

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> m >> S;
        for(int i = 0; i < m; i++)
            cin >> coins[i].first >> coins[i].second;
        for(int i = 0; i < 303; i++)
            for(int j = 0; j < 303; j++)
                dp[i][j] = -1;
        int ans = inf;
        for(int a = 0; a <= S; a++)
            for(int b = 0; b <= S; b++)
                if(a * a + b * b == S * S)
                    ans = min(ans, cdp(a, b));
        if(ans == inf)
            cout << "not possible" << endl;
        else
            cout << ans << endl;
    }
}