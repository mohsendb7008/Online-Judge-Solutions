#include <bits/stdc++.h>
using namespace std;

// Annoying painting tool

int n, m, r, c;
bool grid[103][103], build[103][103];

int main(){
    while(11230){
        cin >> n >> m >> r >> c;
        if(n + m + r + c == 0)
            break;
        char x;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> x;
                grid[i][j] = x == '1';
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                build[i][j] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(build[i][j] != grid[i][j]){
                    if(i + r - 1 >= n || j + c - 1 >= m){
                        ans = -1;
                        break;
                    }
                    ans++;
                    for(int x = i; x < i + r; x++)
                        for(int y = j; y < j + c; y++)
                            build[x][y] = !build[x][y];
                }
            if(ans == -1)
                break;
        }
        cout << ans << endl;
    }
}