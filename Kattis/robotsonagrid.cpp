#include <bits/stdc++.h>
using namespace std;

// Robots on a Grid

#define num long long int

const num mod = INT_MAX;

int n;
char g[1003][1003];
num dp[1003][1003];
bool vis[1003][1003];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

void dfs(int x, int y){
    vis[x][y] = true;
    for(int k = 0; k < 4; k++){
        int u = x + adjR[k], v = y + adjC[k];
        if(u >= 0 && u < n && v >= 0 && v < n && g[u][v] != '#' && !vis[u][v])
            dfs(u, v);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            dp[i][j] = !(i + j);
            if(g[i][j] == '#')
                continue;
            if(i > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    if(dp[n-1][n-1]){
        cout << dp[n-1][n-1] << endl;
        return 0;
    }
    dfs(0, 0);
    cout << (vis[n-1][n-1] ? "THE GAME IS A LIE" : "INCONCEIVABLE ") << endl;
}