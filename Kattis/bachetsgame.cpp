#include <bits/stdc++.h>
using namespace std;

// Bachet's Game

#define P false
#define N true

int n, m, a[13];
bool dp[1000003];

int main(){
    while(cin >> n >> m){
        for(int i = 0; i < m; i++)
            cin >> a[i];
        dp[0] = P;
        for(int i = 1; i <= n; i++){
            dp[i] = P;
            for(int j = 0; j < m; j++)
                if(i - a[j] >= 0 && dp[i-a[j]] == P){
                    dp[i] = N;
                    break;
                }
        }
        cout << (dp[n] ? "Stan wins" : "Ollie wins") << endl;
    }
}