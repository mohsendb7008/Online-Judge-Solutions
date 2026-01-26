#include <iostream>
#include <climits>
using namespace std;

int active[90];
pair<int, int>dp[91][1801][5][5];

inline void relax(const int i, const int cap, const int streakA, const int streakB, const pair<int, int>& transition) {
    const int A1 = dp[i][cap][streakA][streakB].first;
    const int B1 = dp[i][cap][streakA][streakB].second;
    const int diff1 = A1 - B1;
    const int A2 = transition.first;
    const int B2 = transition.second;
    const int diff2 = A2 - B2;
    if (diff2 > diff1 || (diff2 == diff1 && A2 > A1)) {
        dp[i][cap][streakA][streakB] = make_pair(A2, B2);
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
        for (int cap = 0; cap <= n * t; cap++) {
           for (int streakA = 0; streakA < 5; streakA++) {
               for (int streakB = 0; streakB < 5; streakB++) {
                   dp[i][cap][streakA][streakB] = make_pair(INT_MIN, 0);
                   if (i == 90) {
                       dp[i][cap][streakA][streakB] = make_pair(0, 0);
                   }
                   else if (i < 90) {
                       auto transition1 = dp[i + 1][cap][0][i != 44 && active[i] ? (streakB + 1) % 5 : 0];
                       if (active[i] && streakB == 4) {
                           transition1.second++;
                       }
                       relax(i, cap, streakA, streakB, transition1);
                       if (min(cap, n) >= active[i]) {
                           auto transition2 = dp[i + 1][cap - active[i]][0][0];
                           relax(i, cap, streakA, streakB, transition2);
                       }
                       if (min(cap, n) >= active[i] + 1) {
                           auto transition3 = dp[i + 1][cap - active[i] - 1][i != 44 ? (streakA + 1) % 5 : 0][0];
                           if (streakA == 4) {
                               transition3.first++;
                           }
                           relax(i, cap, streakA, streakB, transition3);
                       }
                   }
               }
           }
        }
    }
    const auto ans = dp[0][n * t][0][0];
    cout << ans.first << " " << ans.second << endl;
}
