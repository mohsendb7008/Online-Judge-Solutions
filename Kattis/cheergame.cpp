#include <iostream>
#include <climits>
using namespace std;

int active[90];
pair<int, int> dp[91][1801][5][5];

inline void relax(const int i, const int j, const int a, const int b, const pair<int, int>& sub) {
    const int A1 = dp[i][j][a][b].first;
    const int B1 = dp[i][j][a][b].second;
    const int diff1 = A1 - B1;
    const int A2 = sub.first;
    const int B2 = sub.second;
    const int diff2 = A2 - B2;
    if (diff2 > diff1 || (diff2 == diff1 && A2 > A1)) {
        dp[i][j][a][b] = make_pair(A2, B2);
    }
}

int main() {
    int n, t, m;
    cin >> n >> t >> m;
    fill_n(active, 90, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++) {
            active[i]++;
        }
    }
    for (int i = 90; i >= 0; i--) {
        for (int j = 0; j <= n * t; j++) {
           for (int a = 0; a < 5; a++) {
               for (int b = 0; b < 5; b++) {
                   dp[i][j][a][b] = make_pair(INT_MIN, 0);
                   if (i == 90) {
                       dp[i][j][a][b] = make_pair(0, 0);
                   }
                   else if (i < 90) {
                       auto sub1 = dp[i + 1][j][0][i != 44 && active[i] ? (b + 1) % 5 : 0];
                       if (active[i] && b == 4) {
                           sub1.second++;
                       }
                       relax(i, j, a, b, sub1);
                       if (min(j, n) >= active[i]) {
                           auto sub2 = dp[i + 1][j - active[i]][0][0];
                           relax(i, j, a, b, sub2);
                       }
                       if (min(j, n) >= active[i] + 1) {
                           auto sub3 = dp[i + 1][j - active[i] - 1][i != 44 ? (a + 1) % 5 : 0][0];
                           if (a == 4) {
                               sub3.first++;
                           }
                           relax(i, j, a, b, sub3);
                       }
                   }
               }
           }
        }
    }
    const auto ans = dp[0][n * t][0][0];
    cout << ans.first << " " << ans.second << endl;
}