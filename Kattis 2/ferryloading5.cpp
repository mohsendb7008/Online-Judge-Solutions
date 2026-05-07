#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int w[101];
bool dp[500001];
int par[500001];

int main() {
    int n;
    while (cin >> n && n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            double x;
            cin >> x;
            w[i] = static_cast<int>(round(x * 50.0));
            sum += w[i];
        }
        sum /= 2;
        for (int s = 0; s <= sum; s++) {
            dp[s] = false;
        }
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int s = sum; s >= w[i]; s--) {
                if (!dp[s] && dp[s - w[i]]) {
                    dp[s] = true;
                    par[s] = i;
                }
            }
        }
        int target = sum;
        while (!dp[target])
            target--;
        vector<int> ans;
        while (target) {
            ans.push_back(par[target] + 1);
            target -= w[par[target]];
        }
        sort(ans.begin(), ans.end());
        for (const int i : ans)
            cout << i << " ";
        cout << endl;
    }
}