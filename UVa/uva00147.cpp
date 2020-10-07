#include <bits/stdc++.h>
using namespace std;

// Dollars

#define num long long int

num coins[11]{5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
num dp[30003][14];

int main(){
    for(int i = 0; i <= 30000; i++)
        for(int j = 0; j < 11; j++){
            if(i == 0)
                dp[i][j] = 1;
            else{
                dp[i][j] = j > 0 ? dp[i][j-1] : 0;
                if(i - coins[j] >= 0)
                    dp[i][j] += dp[i-coins[j]][j];
            }
        }
    double q;
    cin >> q;
    do{
        printf("%6.2f%17lld\n", q, dp[static_cast<int> (q * 100.0 + 0.5)][10]);
        cin >> q;
    }while(q != 0);
}