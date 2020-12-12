#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
const int inf = INT_MAX;

int n, p[maxn], dp[maxn][3];

int cdp(int i, int k){
    if(dp[i][k] != -1)
        return dp[i][k];
    if(i == n)
        return dp[i][k] = k ? (inf) : (0);
    int ans = INT_MAX;
    if(k)
        ans = min(ans, cdp(i+1, k-1));
    if(i + 2 < n)
        ans = min(ans, max(p[i+2] - p[i], cdp(i+3, k)));
    return dp[i][k] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = -1;
    cout << cdp(0, n % 3) << endl;
}