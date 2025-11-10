#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c, w;
    cin >> n >> c;
    vector<int> dp(c + 1, -1);
    dp[0] = c+1;
    while(n--){
        cin >> w;
        vector<int> newdp(c + 1, -1);
        for (int s = 0; s <= c; ++s) {
            if (dp[s] == -1) continue;
            newdp[s] = max(newdp[s], min(dp[s], w));
            if (s + w <= c)
                newdp[s + w] = max(newdp[s + w], dp[s]);
        }
        dp.swap(newdp);
    }
    int ans = 0;
    while (ans <= c && (dp[ans] == -1 || ans + dp[ans] <= c)) ans++;
    if (ans > c) ans = 0;
    cout << ans << endl;
}
