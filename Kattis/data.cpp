#include <bits/stdc++.h>
using namespace std;

// Big Data

int n, s[17], dp[(1<<14)+3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int mask = 1; mask < (1<<n); mask++){
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(mask & (1<<i))
                sum += s[i];
        int d = 2;
        while(sum > 1){
            if(!(sum % d))
                dp[mask]++;
            while(!(sum % d))
                sum /= d;
            d++;
        }
    }
    for(int mask = 1; mask < (1<<n); mask++){
        int prevy = (mask - 1) & mask;
        while(prevy != 0)
            dp[mask] = max(dp[mask], dp[prevy] + dp[mask - prevy]), prevy = (prevy - 1) & mask;
    }
    cout << dp[(1<<n)-1] << endl;
}