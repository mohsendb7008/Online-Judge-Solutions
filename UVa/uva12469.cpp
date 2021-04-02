#include <bits/stdc++.h>
using namespace std;

// Stones

#define P false
#define N true

bool dp[1003][1003];

int main(){
    dp[0][0] = P;
    for(int i = 1; i <= 1000; i++)
        for(int j = 1; j <= i; j++){
            dp[i][j] = (j > 1) ? dp[i][j-1] : P;
            if(dp[i-j][min(2*j, i-j)] == P)
                dp[i][j] = N;
        }
    int t;
    while(12469){
        cin >> t;
        if(!t)
            break;
        bool ans = P;
        for(int i = 1; i < t; i++)
            if(dp[t-i][min(2*i, t-i)] == P){
                ans = N;
                break;
            }
        cout << (ans ? "Alicia" : "Roberto") << endl;
    }
}