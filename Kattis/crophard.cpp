#include <bits/stdc++.h>
using namespace std;

// Crop Triangles (Hard)

#define num long long int

num t, n, A, B, C, D, x, y, M, grid[3][3], ans;

int main(){
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> A >> B >> C >> D >> x >> y >> M;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                grid[i][j] = 0;
        grid[x%3][y%3]++;
        for(int i = 1; i < n; i++){
            x = (A * x + B) % M;
            y = (C * y + D) % M;
            grid[x%3][y%3]++;
        }
        ans = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(grid[i][j] >= 3)
                    ans += (grid[i][j] * (grid[i][j] - 1) * (grid[i][j] - 2)) / 6;
        for(int i = 0; i < 9; i++)
            for(int j = i + 1; j < 9; j++)
                for(int k = j + 1; k < 9; k++){
                    int x1 = i / 3, y1 = i % 3;
                    int x2 = j / 3, y2 = j % 3;
                    int x3 = k / 3, y3 = k % 3;
                    if(!((x1+x2+x3)%3) && !((y1+y2+y3)%3))
                        ans += grid[x1][y1] * grid[x2][y2] * grid[x3][y3];
                }
        cout << "Case #" << test << ": " << ans << endl;
    }
}