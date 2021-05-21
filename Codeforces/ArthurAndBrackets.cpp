#include <bits/stdc++.h>
using namespace std;

const int maxn = 603;
const int inf = INT_MAX;

int n, l[maxn], r[maxn], dp[maxn][maxn];

int cdp(int i, int n){
    if(dp[i][n] != -1)
        return dp[i][n];
    if(!n)
        return dp[i][n] = 0;
    for(int k = l[i]; k <= r[i]; k++)
        if((k % 2) && (k / 2 < n) && cdp(i + 1, k / 2) != inf && cdp(i + k / 2 + 1, n - (k / 2 + 1)) != inf)
            return dp[i][n] = k;
    return dp[i][n] = inf;
}

void build_ans(int i, int n){
    if(!n)
        return;
    int k = dp[i][n];
    cout << '(';
    build_ans(i + 1, k / 2);
    cout << ')';
    build_ans(i + k / 2 + 1, n - (k / 2 + 1));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
    if(cdp(0, n) == inf){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    build_ans(0, n);
    cout << '\n';
}