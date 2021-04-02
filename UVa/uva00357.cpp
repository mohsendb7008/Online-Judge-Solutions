#include <bits/stdc++.h>
using namespace std;

// Let Me Count The Ways

vector<int> coins{1, 5, 10, 25, 50};
long long int dp[30003][8];

int main(){
    for(int c = 0; c < 5; c++)
        dp[0][c] = 1;
    for(int i = 1; i <= 30000; i++){
        for(int c = 0; c < 5; c++){
            dp[i][c] = c > 0 ? dp[i][c-1] : 0;
            if(i - coins[c] >= 0)
                dp[i][c] += dp[i - coins[c]][c];
        }
    }
    int q;
    while(cin >> q){
        if(dp[q][4] == 1)
            printf("There is only 1 way to produce %d cents change.\n", q);
        else printf("There are %lld ways to produce %d cents change.\n", dp[q][4], q);
    }
}