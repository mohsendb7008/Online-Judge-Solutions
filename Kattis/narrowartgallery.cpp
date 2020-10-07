#include <bits/stdc++.h>
using namespace std;

// Narrow Art Gallery

int N, K;
int gallery[203][5];

int dp[203][203][5];

int cdp(int n, int k, int s){
    if(n == -1)
        return k == 0 ? 0 : -2;
    if(dp[n][k][s] != -1)
        return dp[n][k][s];
    int ans = cdp(n-1, k, 0);
    if(ans != -2)
        ans += gallery[n][0] + gallery[n][1];
    if(k > 0){
        if(s != 1){
            int subp1 = cdp(n-1, k-1, 2);
            if(subp1 != -2)
                ans = max(ans, gallery[n][1] + subp1);
        }
        if(s != 2){
            int subp2 = cdp(n-1, k-1, 1);
            if(subp2 != -2)
                ans = max(ans, gallery[n][0] + subp2);
        }
    }
    return dp[n][k][s] = ans;
}

int main(){
    while(1){
        cin >> N >> K;
        if(N + K == 0)
            break;
        for(int i = 0; i < N; i++)
            cin >> gallery[i][0] >> gallery[i][1];
        for(int i = 0; i < 203; i++)
            for(int j = 0; j < 203; j++)
                for(int k = 0; k < 5; k++)
                    dp[i][j][k] = -1;
        cout << cdp(N-1, K, 0) << endl;
    }
}