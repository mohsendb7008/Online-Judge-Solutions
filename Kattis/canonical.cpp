#include <bits/stdc++.h>
using namespace std;

// Canonical Coin Systems 

int n;
int coins[103];
int dp[2000003];

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    dp[0] = 0;
    int total = coins[n-1] + coins[n-2];
    for (int i = 1; i < total; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if(i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
        int ans = 0, c = i;
        while(c){
            int j = upper_bound(coins, coins + n, c) - 1 - coins;
            ans += c / coins[j];
            c %= coins[j];
        }
        if(ans != dp[i]){
            cout << "non-canonical" << endl;
            return 0;
        }
    }
    cout << "canonical" << endl;
    return 0;
}