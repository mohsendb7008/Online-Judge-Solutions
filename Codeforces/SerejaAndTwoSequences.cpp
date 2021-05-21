#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m, s, e, a[maxn], b[maxn], dp[maxn][303];
vector<int> ind[maxn];

int main(){
    cin >> n >> m >> s >> e;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < m; i++)
        ind[b[i]].push_back(i);
    int ops = s/e;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= ops; j++){
            if(!j){
                dp[i][j] = -1;
                continue;
            }
            dp[i][j] = INT_MAX;
            if(!i)
                continue;
            if(dp[i-1][j] != -1)
                dp[i][j] = dp[i-1][j];
            int k = dp[i-1][j-1];
            if(k == INT_MAX)
                continue;
            auto it = upper_bound(ind[a[i]].begin(), ind[a[i]].end(), k);
            if(it != ind[a[i]].end())
                dp[i][j] = min(dp[i][j], *it);
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= ops; j++)
            if(dp[i][j] != INT_MAX && s >= j*e+i+dp[i][j]+1)
                ans = max(ans, j);
    cout << ans << endl;
}