#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
const int inf = INT_MAX;

int n, h[maxn], c[maxn], dp[maxn][3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i] >> c[i];
    dp[n-1][0] = 0, dp[n-1][1] = c[n-1], dp[n-1][2] = 2 * c[n-1];
    for(int i = n-2; i >= 0; i--)
        for(int j = 0; j < 3; j++){
            dp[i][j] = inf;
            for(int k = 0; k < 3; k++)
                if(h[i] + j != h[i + 1] + k && dp[i + 1][k] != inf)
                    dp[i][j] = min(dp[i][j], j * c[i] + dp[i + 1][k]);
        }
    cout << min(dp[0][0], min(dp[0][1], dp[0][2])) << endl;
}