#include <iostream>
#include <vector>
#define inf numeric_limits<int>::max()

using namespace std;

int n, c, v[60], w[60], all[2][(1 << 23) + 1], dp[2][(1 << 26) + 1];

inline int tryAll(const int l, const int r) {
    int best = 0;
    all[0][0] = all[1][0] = 0;
    for (int mask = 1; mask < 1 << (r - l + 1); mask++) {
        const int i = __builtin_ctz(mask);
        all[0][mask] = all[0][mask ^ 1 << i] + v[i + l];
        all[1][mask] = all[1][mask ^ 1 << i] + w[i + l];
        if (all[1][mask] <= c) {
            best = max(best, all[0][mask]);
            dp[r % 2][all[0][mask]] = min(dp[r % 2][all[0][mask]], all[1][mask]);
        }
    }
    return best;
}

inline vector<pair<int, int>> knapsack(const int sumV, const int l, const int r) {
    const int mid = min(l + 22, r);
    for (int profit = 0; profit <= sumV; profit++) {
        dp[mid % 2][profit] = profit ? inf : 0;
    }
    tryAll(l, mid);
    for (int i = mid + 1; i <= r; i++) {
        for (int profit = 0; profit <= sumV; profit++) {
            dp[i % 2][profit] = dp[1 - i % 2][profit];
            if (profit - v[i] >= 0 && dp[1 - i % 2][profit - v[i]] != inf) {
                dp[i % 2][profit] = min(dp[i % 2][profit], dp[1 - i % 2][profit - v[i]] + w[i]);
            }
        }
    }
    vector<pair<int, int>> costProfit;
    for (int profit = 0; profit <= sumV; profit++) {
        if (dp[r % 2][profit] <= c) {
            costProfit.emplace_back(dp[r % 2][profit], profit);
        }
    }
    sort(costProfit.begin(), costProfit.end());
    return costProfit;
}

inline int merge(const vector<pair<int, int>> &cp1, const vector<pair<int, int>> &cp2, const bool flip = true) {
    vector<pair<int, int>> maxProfit(cp2.size());
    for (int i = 0; i < maxProfit.size(); i++) {
        maxProfit[i] = make_pair(cp2[i].first, max(cp2[i].second, i ? maxProfit[i-1].second : 0));
    }
    int best = 0;
    for (const pair<int, int> &cp : cp1) {
        const int pl = cp.second;
        const int rem = c - cp.first;
        const int j = upper_bound(maxProfit.begin(), maxProfit.end(), make_pair(rem, inf)) - maxProfit.begin();
        const int pr = j ? maxProfit[j-1].second : 0;
        best = max(best, pl + pr);
    }
    if (flip)
        best = max(best, merge(cp2, cp1, false));
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        int ans = 0;
        if (n <= 23) {
            ans = tryAll(0, n - 1);
        }
        else {
            int sumV = 0;
            for (int i = 0; i < n; i++) {
                sumV += v[i];
            }
            ans = merge(knapsack(sumV, 0, n / 2), knapsack(sumV, n / 2 + 1, n - 1));
        }
        cout << ans << endl;
    }
}