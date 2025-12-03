#include <bits/stdc++.h>
using namespace std;

const int MAXR = 50000 + 5;
const int MAXC = 10 + 5;

int R, C;
char grid[MAXR][MAXC];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    for (int c = 0; c < C; c++) {
        int write = R - 1;
        int count = 0;

        for (int r = R - 1; r >= 0; r--) {
            if (grid[r][c] == 'a') {
                count++;
                grid[r][c] = '.';
            } else if (grid[r][c] == '#') {
                for (; count > 0; count--) {
                    grid[write][c] = 'a';
                    write--;
                }
                write = r - 1;
            }
        }

        for (; count > 0; count--) {
            grid[write][c] = 'a';
            write--;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
