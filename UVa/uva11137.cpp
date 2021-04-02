#include <bits/stdc++.h>
using namespace std;

// Ingenuous Cubrency

int coins[21] {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

long long dp[10002][24];

int main(){

    for(int i = 0; i < 10000; i++)
        for(int j = 0; j < 21; j++){
            if(i == 0)
                dp[i][j] = 1;
            else{
                dp[i][j] = 0;
                if(j != 0)
                    dp[i][j] = dp[i][j-1];
                if(i-coins[j] >= 0)
                    dp[i][j] += + dp[i-coins[j]][j];
            }
        }
    
    int n;
    while(cin >> n)
        cout << dp[n][20] << endl;
}