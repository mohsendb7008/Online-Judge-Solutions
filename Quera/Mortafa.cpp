#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

int N, H;
num dp[503][503];

int main(){
    cin >> N >> H;
    for(int n = 0; n <= N; n++)
        for(int h = 0; h <= H; h++){
            if(!n)
                dp[n][h] = 1;
            else if(!h)
                dp[n][h] = 0;
            else for(int i = 0; i < n; i++)
                dp[n][h] = (dp[n][h] + (dp[i][h - 1] * dp[n - 1 - i][h - 1]) % mod) % mod;
        }
    cout << (dp[N][H] - dp[N][H - 1] + mod) % mod << endl;
}