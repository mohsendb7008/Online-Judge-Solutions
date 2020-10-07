#include <bits/stdc++.h>
using namespace std;

// Divisibility

int n, k;
int nums[10003];
int dp[10003][103];

bool cdp(int i, int r){
    if(i == -1)
        return r == 0;
    if(dp[i][r] != -1)
        return dp[i][r];
    return dp[i][r] = cdp(i-1, (r - nums[i] + k) % k) || cdp(i-1, (r + nums[i]) % k);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 10003; i++)
            for(int j = 0; j < 103; j++)
                dp[i][j] = -1;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> nums[i], nums[i] = (nums[i] + 5000 * k) % k;
        cout << (cdp(n-1, 0) ? "Divisible" : "Not divisible") << endl;
    }
}