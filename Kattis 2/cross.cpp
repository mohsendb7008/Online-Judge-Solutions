#include <iostream>
#include <vector>
#include <string>

using namespace std;

char g[9][9];

inline bool valid(const int r, const int c) {
    for (int i = 0; i < 9; i++) {
        if (i != c && g[r][i] == g[r][c])
            return false;
        if (i != r && g[i][c] == g[r][c])
            return false;
    }
    const int br = r / 3 * 3;
    const int bc = c / 3 * 3;
    for (int i = br; i < br + 3; i++) {
        for (int j = bc; j < bc + 3; j++) {
            if ((i != r || j != c) && g[i][j] == g[r][c]) {
                return false;
            }
        }
    }
    return true;
}

inline bool check_initial() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (g[i][j] != '.') {
                if (!valid(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> g[i][j];
        }
    }
    if (!check_initial()) {
        cout << "ERROR" << endl;
        return 0;
    }
    bool changed = true;
    while (changed) {
        changed = false;
        for (char d = '1'; d <= '9'; d++) {
            for (int br = 0; br < 3; br++) {
                for (int bc = 0; bc < 3; bc++) {
                    bool already = false;
                    for (int i = br * 3; i < br * 3 + 3; i++) {
                        for (int j = bc * 3; j < bc * 3 + 3; j++) {
                            if (g[i][j] == d) {
                                already = true;
                            }
                        }
                    }
                    if (already)
                        continue;
                    vector<pair<int,int>> pos;
                    for (int i = br * 3; i < br * 3 + 3; i++) {
                        for (int j = bc * 3; j < bc * 3 + 3; j++) {
                            if (g[i][j] != '.')
                                continue;
                            bool ok = true;
                            for (int k = 0; k < 9; k++) {
                                if (g[i][k] == d || g[k][j] == d)
                                    ok = false;
                            }
                            for (int r = br * 3; r < br * 3 + 3; r++) {
                                for (int c = bc * 3; c < bc * 3 + 3; c++) {
                                    if (g[r][c] == d)
                                        ok = false;
                                }
                            }
                            if (ok) {
                                pos.emplace_back(i, j);
                            }
                        }
                    }
                    if (pos.empty()) {
                        cout << "ERROR" << endl;
                        return 0;
                    }
                    if (pos.size() == 1) {
                        g[pos[0].first][pos[0].second] = d;
                        changed = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
}