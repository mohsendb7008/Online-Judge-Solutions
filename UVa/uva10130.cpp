#include <bits/stdc++.h>
using namespace std;

// SuperSale

int dp[1003][33], n;
pair<int, int> products[1003];

int cdp(int i, int w){
    if(i == -1)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    dp[i][w] = cdp(i-1, w);
    if(w >= products[i].second)
        dp[i][w] = max(dp[i][w], cdp(i-1, w-products[i].second) + products[i].first);
    return dp[i][w];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 1003; i++)
            for(int j = 0; j < 33; j++)
                dp[i][j] = -1;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> products[i].first >> products[i].second;
        int g;
        cin >> g;
        int ans = 0;
        for(int i = 0; i < g; i++){
            int w;
            cin >> w;
            ans += cdp(n-1, w);
        }
        cout << ans << endl;
    }
}