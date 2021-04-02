#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, g[103][103];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    for(int i = 1; i < n-1; i++)
        for(int j = 1; j < m-1; j++)
            if((g[i][j] > g[i][j - 1] && g[i][j] > g[i][j + 1] && g[i][j] < g[i - 1][j] && g[i][j] < g[i + 1][j]) 
            || (g[i][j] < g[i][j - 1] && g[i][j] < g[i][j + 1] && g[i][j] > g[i - 1][j] && g[i][j] > g[i + 1][j]))
                ans++;
    cout << ans << endl;
}