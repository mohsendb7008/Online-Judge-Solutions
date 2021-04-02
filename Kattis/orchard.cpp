#include <bits/stdc++.h>
using namespace std;

// First Orchard

double dp[5][5][5][5][9];

double cdp(int r, int g, int b, int y, int s){
    if(dp[r][g][b][y][s] != -1)
        return dp[r][g][b][y][s];
    if(!(r + g + b + y))
        return dp[r][g][b][y][s] = 1;
    if(!s)
        return dp[r][g][b][y][s] = 0;
    double ans = 0;
    int fr = 0;
    if(r)
        ans += cdp(r-1, g, b, y, s) / 6;
    else 
        fr++;
    if(g)
        ans += cdp(r, g-1, b, y, s) / 6;
    else 
        fr++;
    if(b)
        ans += cdp(r, g, b-1, y, s) / 6;
    else
        fr++;
    if(y)
        ans += cdp(r, g, b, y-1, s) / 6;
    else 
        fr++;
    int mx = max(r, max(g, max(b, y)));
    double subp = 0;
    int tot = 0;
    if(r == mx)
        subp += cdp(r-1, g, b, y, s), tot++;
    if(g == mx)
        subp += cdp(r, g-1, b, y, s), tot++;
    if(b == mx)
        subp += cdp(r, g, b-1, y, s), tot++;
    if(y == mx)
        subp += cdp(r, g, b, y-1, s), tot++;
    ans += subp / (tot * 6);
    ans += cdp(r, g, b, y, s - 1) / 6;
    return dp[r][g][b][y][s] = (6 * ans) / (6 - fr);
}

int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                for(int x = 0; x < 5; x++)
                    for(int y = 0; y < 9; y++)
                        dp[i][j][k][x][y] = -1;
    int r, g, b, y, s;
    cin >> r >> g >> b >> y >> s;
    cout << fixed << setprecision(10) << cdp(r, g, b, y, s) << endl;
}