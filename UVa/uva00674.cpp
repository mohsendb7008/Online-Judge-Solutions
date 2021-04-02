#include <bits/stdc++.h>
using namespace std;

// Coin Change

#define num long long int

vector<int> coins{1, 5, 10, 25, 50};
num dp[7492][8];

int main(){
    for(int i = 0; i < 5; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= 7489; i++)
        for(int c = 0; c < 5; c++){
            dp[i][c] = c > 0 ? dp[i][c-1] : 0;
            if(i - coins[c] >= 0)
                dp[i][c] += dp[i-coins[c]][c]; 
        }
    int q;
    while(cin >> q)
        cout << dp[q][4] << endl;
}