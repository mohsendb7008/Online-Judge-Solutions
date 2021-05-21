#include <bits/stdc++.h>
using namespace std;

int w[13], m, dp[1003][13][13];

int cdp(int i, int d, int l){
    if(dp[i][d][l] != -1)
        return dp[i][d][l];
    if(i == m)
        return dp[i][d][l] = 11;
    for(int j = d + 1; j <= 10; j++)
        if(w[j] && j != l && cdp(i + 1, j - d, j))
            return dp[i][d][l] = j;
    return dp[i][d][l] = 0;
}

int main(){
    for(int i = 1; i <= 10; i++){
        char c;
        cin >> c;
        w[i] = c == '1';
    }
    cin >> m;
    for(int i = 0; i < 1003; i++)
        for(int j = 0; j < 13; j++)
            for(int k = 0; k < 13; k++)
                dp[i][j][k] = -1;
    if(cdp(0, 0, 0)){
        cout << "YES" << endl;
        int d = 0, l = 0;
        for(int i = 0; i < m; i++){
            int j = dp[i][d][l];
            cout << j << " ";
            d = j - d, l = j;
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
}