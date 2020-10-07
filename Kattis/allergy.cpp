#include <bits/stdc++.h>
using namespace std;

// Alergy Test

int k;
int D[23];

int dp[(1<<21)+3][10];

int cdp(int mask, int c){
    if(dp[mask][c] != -1)
        return dp[mask][c];
    if(mask == 0)
        return dp[mask][c] = c;
    int ans = INT_MAX;
    for(int x = 0; x < k; x++)
        if(mask & (1<<x))
            ans = min(ans, c + 1 + cdp(mask - (1<<x), max(0, D[x]-1-c)));
    return dp[mask][c] = ans;
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> D[i];
    for(int i = 0; i < (1<<21) + 3; i++)
        for(int j = 0; j < 10; j++)
            dp[i][j] = -1;
    cout << cdp((1<<k)-1, 0) << endl;
}