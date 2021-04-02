#include <bits/stdc++.h>
using namespace std;

int l, n;
int bp[53];

int dp[1003][1003];

int cdp(int s, int e){
    if(dp[s][e] != -1)
        return dp[s][e];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        if(bp[i] > s && bp[i] < e)
            ans = min(ans, cdp(s, bp[i]) + cdp(bp[i], e) + e - s);
    return dp[s][e] = (ans == INT_MAX) ? 0 : ans;
}

int main(){
    while(true){
        cin >> l;
        if(l == 0)
            break;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> bp[i];
        for(int i = 0; i < 1003; i++)
            for(int j = 0; j < 1003; j++)
                dp[i][j] = -1;
        printf("The minimum cutting is %d.\n", cdp(0, l));
    }
}