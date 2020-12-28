#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;
const int maxn = 1e5 + 3;

int n;
num dp[maxn][13];
set<num> forbid{3, 5, 6, 7};
int main(){
    cin >> n;
    for(int i = n; i >= 0; i--)
        for(int mask = 0; mask < 8; mask++){
            if(i >= 3 && forbid.find(mask) != forbid.end())
                continue;
            if(i == n){
                dp[i][mask] = 1;
                continue;
            }
            int nmask = mask;
            if(nmask & 4)
                nmask -= 4;
            nmask *= 2;
            dp[i][mask] = (dp[i + 1][nmask] + dp[i + 1][nmask + 1]) % mod;
        }
    cout << dp[0][0] << endl;
}