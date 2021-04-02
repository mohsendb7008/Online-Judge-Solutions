#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;
const int maxd = 2e5 + 3;

int k, d;
num dp[maxd], psum[maxd], tmp[maxd];

int main(){
    cin >> k >> d;
    int bound = k * d + 1;
    for(int j = 0; j < bound; j++)
        dp[j] = 1, psum[j] = (j + 1) % mod;
    k--;
    while(k--){
        for(int j = 0; j < bound; j++){
            int l = max(0, j-d), r = min(bound-1, j+d);
            dp[j] = (psum[r] - (l ? psum[l-1] : 0) + mod) % mod;
            tmp[j] = (dp[j] + (j ? tmp[j-1] : 0)) % mod;
        }
        copy_n(tmp, bound, psum);
    }
    num ans = 0;
    for(int j = 0; j <= d; j++)
        ans = (ans + dp[j]) % mod;
    cout << ans << endl;
}