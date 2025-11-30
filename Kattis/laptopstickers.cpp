#include <bits/stdc++.h>
using namespace std;

char grid[55][55];

int main() {
    int L, H, K;
    cin >> L >> H >> K;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < L; j++)
            grid[i][j] = '_';

    for (int i = 0; i < K; i++) {
        int l, h, a, b;
        cin >> l >> h >> a >> b;
        char c = 'a' + i;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < l; x++) {
                int yy = b + y, xx = a + x;
                if (xx >= 0 && xx < L && yy >= 0 && yy < H)
                    grid[yy][xx] = c;
            }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}
