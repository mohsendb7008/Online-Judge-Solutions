#include <bits/stdc++.h>
using namespace std;

// Bag of Tiles

#define num long long int

num c[33][33];
int g, m, n, t;
int labels[33];

num dp[33][33][10003];

num cdp(int i, int n, int t){
    if(i == -1)
        return n == 0 && t == 0;
    if(dp[i][n][t] != -1)
        return dp[i][n][t];
    dp[i][n][t] = cdp(i-1, n, t);
    if(n > 0 && t >= labels[i])
        dp[i][n][t] += cdp(i-1, n-1, t-labels[i]);
    return dp[i][n][t];
}

int main(){
    c[0][0] = 1;
    for(int n = 1; n <= 30; n++)
        for(int k = 0; k <= n; k++)
            c[n][k] = c[n-1][k] + (k > 0 ? c[n-1][k-1] : 0);
    cin >> g;
    for(int game = 1; game <= g; game++){
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> labels[i];
        cin >> n >> t;
        for(int i = 0; i < m; i++)
            for(int j = 0; j <= n; j++)
                for(int k = 0; k <= t; k++)
                    dp[i][j][k] = -1;
        num a = cdp(m-1, n, t);
        num b = c[m][n] - a;
        cout << "Game " << game << " -- " << a << " : " << b << endl;
    }
}