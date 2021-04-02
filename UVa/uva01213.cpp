#include <bits/stdc++.h>
using namespace std;

// Sum Of Different Primes

bitset<1121> primeFlags;
vector<int> primes;

int dp[1123][17][190];

int cdp(int n, int k, int p){
    if(p == -1)
        return (n == 0 && k == 0);
    if(dp[n][k][p] != -1)
        return dp[n][k][p];
    int ans = cdp(n, k, p-1);
    if(n >= primes[p] && k != 0)
        ans += cdp(n-primes[p], k-1, p-1);
    return dp[n][k][p] = ans;
}

int main(){
    primeFlags.set();
    primeFlags[0] = 0;
    primeFlags[1] = 0;
    for(int p = 2; p <= 1120; p++)
        if(primeFlags[p]){
            primes.push_back(p);
            for(int q = p * p; q <= 1120; q += p)
                primeFlags[q] = 0;
        }
    for(int n = 0; n <= 1120; n++)
        for(int k = 0; k <= 14; k++)
            for(int p = 0; p <= 186; p++)
                dp[n][k][p] = -1;
    while(true){
        int n, k;
        cin >> n >> k;
        if(n + k == 0)
            break;
        cout << cdp(n, k, 186) << endl;
    }
}