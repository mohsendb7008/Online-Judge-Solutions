#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, B;
num cost[3003];
num dp[3003][3003][3];

num inf = LONG_MAX;

num cdp(int i, int a, int c){
    if(i == -1)
        return 0;
    if(dp[i][a][c] != -1)
        return dp[i][a][c];
    num ans = inf;
    int b = n - 1 - i - a;
    if(c == 0){
        if(B - a > 0){
            ans = cdp(i-1, a + 1, 0);
            num subp = cdp(i-1, a + 1, 1);
            if(subp != inf)
                ans = min(ans, subp + cost[i]);
        }
    }
    else{
        if(B - b > 0){
            ans = cdp(i-1, a, 1);
            num subp = cdp(i-1, a, 0);
            if(subp != inf)
                ans = min(ans, subp + cost[i]);
        }
    }
    return dp[i][a][c] = ans;
}

int main(){
    cin >> n >> B;
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    if(n == 1 || n <= B){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < 3003; i++)
        for(int j = 0; j < 3003; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    cout << min(cdp(n-1, 0, 0), cdp(n-1, 0, 1)) << endl;
}