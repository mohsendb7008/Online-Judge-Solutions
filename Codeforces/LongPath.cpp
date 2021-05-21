#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, p[1003], moves[1003], mark[1003], dp[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    moves[0] = dp[0] = 1;
    for(int i = 1; i < n; i++){
        fill_n(mark, n, 0);
        int j = i, cnt = 0;
        while(p[j] != j)
            j = p[j], mark[j] = 1, cnt++;
        moves[i] = 1 + cnt + i - j;
        for(int k = j; k < i; k++)
            if(!mark[k])
                moves[i] = (moves[i] + moves[k]) % mod;
        dp[i] = (dp[i-1] + 1 + moves[i]) % mod;
    }
    cout << (dp[n-1] + 1) % mod << '\n';
}