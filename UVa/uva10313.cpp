#include <bits/stdc++.h>
using namespace std;

// Pay the Price

#define num unsigned long long int

num dp[303][303][303];

int main(){
    for(int i = 1; i <= 300; i++)
        for(int j = 0; j <= 300; j++)
            dp[0][i][j] = 1;    
    for(int n = 1; n <= 300; n++)
        for(int k = 1; k <= 300; k++)
            for(int l = 0; l <= 300; l++){
                dp[n][k][l] = k  > 1  ? dp[n][k-1][l] : 0;
                if(n - k >= 0 && l - 1 >= 0)
                    dp[n][k][l] += dp[n-k][k][l-1];
            }
    int n, l1, l2;
    while(1){
        string s;
        getline(cin, s);
        int r = sscanf(s.c_str(), "%d %d %d", &n, &l1, &l2);
        if(r == -1)
            break;
        if(r == 1)
             cout << dp[n][300][300] << endl;
         if(r == 2)
             cout << dp[n][300][min(l1, 300)] << endl;
         if(r == 3)
             cout << dp[n][300][min(l2, 300)] - (l1 == 0 ? 0 : dp[n][300][min(l1-1, 300)]) << endl;
    }
}