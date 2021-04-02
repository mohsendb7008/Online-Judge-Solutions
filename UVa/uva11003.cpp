#include <bits/stdc++.h>
using namespace std;

// Boxes

int n;
int W[1003], C[1003];
int dp[1003][3003];

int cdp(int i, int c){
    if(dp[i][c] != -1)
        return dp[i][c];
    if(i == n-1)
        return dp[i][c] = W[i] <= c ? 1 : 0;
    int ans = cdp(i+1, c);
    if(c >= W[i])
        ans = max(ans, cdp(i+1, min(c == 3002 ? c : c-W[i], C[i]))+1);
    return dp[i][c] = ans;
}

int main(){
    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3003; j++)
                dp[i][j] = -1;
        for(int i = 0; i < n; i++){
            int w, c;
            cin >> w >> c;
            W[i] = w;
            C[i] = c;
        }

        int ans = cdp(0, 3002);
        cout << ans << endl;
    }
}