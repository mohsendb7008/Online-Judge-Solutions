#include <bits/stdc++.h>
using namespace std;

// Homer Simpson

int n, m, t;
int dp[10003];

int main(){
    while(cin >> n >> m >> t){
        dp[0] = 0;
        int ls = 0;
        for(int i = 1; i <= t; i++){
            dp[i] = -1;
            if(i - n >= 0 && dp[i-n] != -1)
                dp[i] = max(dp[i], 1 + dp[i-n]);
            if(i - m >= 0 && dp[i-m] != -1)
                dp[i] = max(dp[i], 1 + dp[i-m]);
            if(dp[i] != -1)
                ls = i;
        }
        cout << dp[ls];
        if(ls < t)
            cout << " " << t - ls;
        cout << endl;
    }
}