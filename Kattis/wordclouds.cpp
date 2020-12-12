#include <bits/stdc++.h>
using namespace std;

// Word Clouds Revisited

int n, c, w[5003], h[5003], dp[5003];

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> h[i];
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        dp[i] = INT_MAX;
        int sum = 0, mx = 0;
        for(int j = i; j < n; j++){
            sum += w[j], mx = max(mx, h[j]);
            if(sum > c)
                break;
            dp[i] = min(dp[i], mx + dp[j+1]);
        }
    }
    cout << dp[0] << endl;
}