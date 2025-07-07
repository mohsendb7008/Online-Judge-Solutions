#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> dp(n, 1);
    vector<int> par(n);

    for (int i = 0; i < n; i++)
        par[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i] && dp[i] <= dp[j] + 1) {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
    }

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[idx])
            idx = i;
    }

    vector<int> nums;
    while (idx != par[idx]) {
        nums.push_back(s[idx]);
        idx = par[idx];
    }
    nums.push_back(s[idx]);
    reverse(nums.begin(), nums.end());

    cout << nums.size() << endl;
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}