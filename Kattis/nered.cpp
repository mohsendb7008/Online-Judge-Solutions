#include <bits/stdc++.h>
using namespace std;

// Nered

int n, m, g[103][103], psum[103][103];

inline int get(int i, int j){
    if(i >= 0 && j >= 0)
        return psum[i][j];
    return 0;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = 1;
    int x, y;
    for(int i = 0; i < m; i++)
        cin >> x >> y, g[x-1][y-1] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            psum[i][j] = g[i][j] + get(i-1, j) + get(i, j-1) - get(i-1, j-1);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int x = i; x < n; x++)
                for(int y = j; y < n; y++)
                    if((x - i + 1) * (y - j + 1) == m)
                        ans = min(ans, psum[x][y] - get(i-1, y) - get(x, j-1) + get(i-1, j-1));
    cout << ans << endl;
}