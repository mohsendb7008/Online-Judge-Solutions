#include <iostream>
#include <string>
#include <map>
using namespace std;

string sequence;
int dp[1003][4][4][3][4];
pair<pair<int, int>, pair<int, int>> trace[1003][4][4][3][4];

inline int get_cost(const int x, const int y) {
    if (x == y)
        return 3;
    if ((x + y) % 2)
        return 5;
    return 7;
}

int main() {
    const string code = "LURD";
    map<char, int> m;
    for (int i = 0; i < 4; i++)
        m[code[i]] = i;
    while (true) {
        cin >> sequence;
        if (sequence == "#")
            break;
        const int n = static_cast<int>(sequence.size());
        for (int i = n; i >= 0; i--) {
            for (int l = 0; l < 4; l++) {
                for (int r = 0; r < 4; r++) {
                    for (int b = 0; b < 3; b++) {
                        for (int y = 0; y < 4; y++) {
                            if (i == n) {
                                dp[i][l][r][b][y] = 0;
                            }
                            else {
                                dp[i][l][r][b][y] = numeric_limits<int>::max();
                                if (l == 2 && r == 0)
                                    continue;
                                for (int nl = 0; nl < 4; nl++) {
                                    if (nl == r)
                                        continue;
                                    if (nl != l && l == 1 && r == 0)
                                        continue;
                                    if (nl != l && l == 3 && r == 0)
                                        continue;
                                    if (sequence[i] == '.') {
                                        int cost = nl != l;
                                        if (cost && b == 1) {
                                            cost = get_cost(nl, y);
                                        }
                                        if (dp[i+1][nl][r][cost?1:0][nl] != numeric_limits<int>::max() && dp[i+1][nl][r][cost?1:0][nl] + cost < dp[i][l][r][b][y]) {
                                            dp[i][l][r][b][y] = dp[i+1][nl][r][cost?1:0][nl] + cost;
                                            trace[i][l][r][b][y] = make_pair(make_pair(nl, r), make_pair(cost?1:0, nl));
                                        }
                                    } else if (nl == m[sequence[i]]) {
                                        int cost = 1;
                                        int x = m[sequence[i]];
                                        if (b == 1) {
                                            cost = get_cost(x, y);
                                        }
                                        if (dp[i+1][nl][r][1][x] != numeric_limits<int>::max() && dp[i+1][nl][r][1][x] + cost < dp[i][l][r][b][y]) {
                                            dp[i][l][r][b][y] = dp[i+1][nl][r][1][x] + cost;
                                            trace[i][l][r][b][y] = make_pair(make_pair(nl, r), make_pair(1, x));
                                        }
                                    }
                                }
                                for (int nr = 0; nr < 4; nr++) {
                                    if (nr == l)
                                        continue;
                                    if (nr != r && l == 2 && r == 1)
                                        continue;
                                    if (nr != r && l == 2 && r == 3)
                                        continue;
                                    if (sequence[i] == '.') {
                                        int cost = nr != r;
                                        if (cost && b == 2) {
                                            cost = get_cost(nr, y);
                                        }
                                        if (dp[i+1][l][nr][cost?2:0][nr] != numeric_limits<int>::max() && dp[i+1][l][nr][cost?2:0][nr] + cost < dp[i][l][r][b][y]) {
                                            dp[i][l][r][b][y] = dp[i+1][l][nr][cost?2:0][nr] + cost;
                                            trace[i][l][r][b][y] = make_pair(make_pair(l, nr), make_pair(cost?2:0, nr));
                                        }
                                    } else if (nr == m[sequence[i]]) {
                                        int cost = 1;
                                        int x = m[sequence[i]];
                                        if (b == 2) {
                                            cost = get_cost(x, y);
                                        }
                                        if (dp[i+1][l][nr][2][x] != numeric_limits<int>::max() && dp[i+1][l][nr][2][x] + cost < dp[i][l][r][b][y]) {
                                            dp[i][l][r][b][y] = dp[i+1][l][nr][2][x] + cost;
                                            trace[i][l][r][b][y] = make_pair(make_pair(l, nr), make_pair(2, x));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int l = 0;
        int r = 2;
        int b = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            const pair<pair<int, int>, pair<int, int>> it = trace[i][l][r][b][y];
            if (it.second.first == 0)
                cout << ".";
            else if (it.second.first == 1)
                cout << "L";
            else if (it.second.first == 2)
                cout << "R";
            l = it.first.first;
            r = it.first.second;
            b = it.second.first;
            y = it.second.second;
        }
        cout << endl;
    }
}