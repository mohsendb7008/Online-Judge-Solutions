#include <bits/stdc++.h>
using namespace std;

// Tug of War

const int maxw = 50 * 450;

int n, a[101], sum = 0, dp[101][51][maxw + 1];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    for(int w = 0; w <= maxw; w++)
        dp[0][0][w] = abs(2 * w - sum);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= min(i, n/2); j++)
            for(int w = 0; w <= maxw; w++){
                dp[i][j][w] = INT_MAX;
                if(j > 0)
                    dp[i][j][w] = min(dp[i][j][w], dp[i-1][j-1][w + a[i]]);
                if(j < i)
                    dp[i][j][w] = min(dp[i][j][w], dp[i-1][j][w]);  
            }
    int diff = dp[n][n/2][0];
    int a = (sum - diff) / 2, b = a + diff;
    cout << a << " " << b << endl;
}