#include <bits/stdc++.h>
using namespace std;

// Tri Tiling

#define num long long int

num dp[31];

int main(){
    dp[0] = 1;
    for(int i = 2; i <= 30; i += 2){
        dp[i] = 3 * dp[i - 2];
        for(int j = 0; j <= i - 4; j += 2)
            dp[i] += 2 * dp[j];
    }
    int x;
    while(1){
        cin >> x;
        if(x == -1)
            break;
        cout << dp[x] << endl;
    }
}