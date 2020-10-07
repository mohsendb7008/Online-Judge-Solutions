#include <bits/stdc++.h>
using namespace std;

// Divisible Group Sums

#define num long long int

int n, q, d, m;
num arr[203];
num dp[203][13][23];


num cdp(int i, int m, int r){
    if(i == -1)
        return m == 0 && r == 0;
    if(dp[i][m][r] != -1)
        return dp[i][m][r];
    return dp[i][m][r] = cdp(i-1, m, r) + (m > 0 ? cdp(i-1, m-1, (r-(arr[i]%d)+d)%d) : 0);
}

num solve(){
    for(int i = 0; i < 203; i++)
        for(int j = 0; j < 13; j++)
            for(int k = 0; k < 23; k++)
                dp[i][j][k] = -1;
    return cdp(n-1, m, 0);
}

int main(){
    int test = 1;
    while(1){
        cin >> n >> q;
        if(n + q == 0)
            break;
        for(int i = 0; i < n; i++)
                cin >> arr[i];
        cout << "SET " << test++ << ":" << endl;
        for(int i = 1; i <= q; i++){
            cin >> d >> m;
            cout << "QUERY " << i << ": " << solve() << endl;
        }
    }
}