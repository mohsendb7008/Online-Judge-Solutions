#include <bits/stdc++.h>
using namespace std;

// Better Productivity

int n, p, a[203], b[203];
vector<pair<int, int>> good, bad;

int dp[203][203];

bool cmp(pair<int, int>& p1, pair<int, int>& p2){
    return p1.second - p1.first > p2.second - p2.first;
}

vector<int> gsum;

int main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++){
        bool ib = true;
        for(int j = 0; j < n; j++)
            if(j != i && (a[j] >= a[i] && b[j] <= b[i]) && !(a[j] == a[i] && b[j] == b[i])){
                ib = false;
                break;
            }
        if(!ib)
            good.push_back({a[i], b[i]});
        else
            bad.push_back({a[i], b[i]});
    }
    sort(bad.begin(), bad.end());
    for(int i = bad.size(); i >= 0; i--)
        for(int k = 0; k <= p; k++){
            dp[i][k] = -1;
            if(i == bad.size() && k == 0)
                dp[i][k] = 0;
            else if(i != bad.size() && k != 0){
                int l = INT_MIN, r = INT_MAX;
                for(int j = i; j < bad.size(); j++){
                    l = max(l, bad[j].first), r = min(r, bad[j].second);
                    if(l >= r)
                        break;
                    if(dp[j+1][k-1] != -1)
                        dp[i][k] = max(dp[i][k], r - l + dp[j+1][k-1]);
                }
            }
        }
    sort(good.begin(), good.end(), cmp);
    if(!good.empty()){
        gsum.push_back(good[0].second - good[0].first);
        for(int i = 1; i < good.size(); i++)
            gsum.push_back(gsum.back() + good[i].second - good[i].first);
    }
    int ans = dp[0][p];
    for(int t = 1; t < p; t++)
        if(dp[0][t] != -1 && p - t - 1 < gsum.size())
            ans = max(ans, dp[0][t] + gsum[p - t - 1]);
    cout << ans << endl;
}