#include <bits/stdc++.h>
using namespace std;

// Compositions

#define num long long int

int p, t, n, m, k;
num dp[33];

int main(){
    dp[0] = 1;
    cin >> p;
    while(p--){
        cin >> t >> n >> m >> k;
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            for(int d = 1; d <= i; d++)
                if(d % k != m)
                    dp[i] += dp[i-d];
        }
        cout << t << " " << dp[n] << endl;
    }
}