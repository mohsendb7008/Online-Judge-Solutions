#include <bits/stdc++.h>
using namespace std;

#define num long long int

num dp[25 + 3];

int main(){
    int n;
    cin >> n;
    if(n % 2){
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for(int i = 2; i <= n; i += 2){
        dp[i] = 3 * dp[i - 2];
        for(int j = 0; j <= i - 4; j += 2)
            dp[i] += 2 * dp[j];
    }
    cout << 2 * dp[n] << endl;
}