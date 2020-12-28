#include <bits/stdc++.h>
using namespace std;

#define num long long int

num x, n, dp[1003][33];

inline num p(num a){
    num ans = 1, rep = n;
    while(rep--)
        ans = ans * a;
    return ans;
}

int main(){
    cin >> x >> n;
    for(num i = 0; i <= x; i++)
        for(num b = 0; b <= 31; b++){
            if(!(i + b))
                dp[i][b] = 1;
            else{
                dp[i][b] = 0;
                if(b)
                    dp[i][b] += dp[i][b-1];
                if(b && i >= p(b))
                    dp[i][b] += dp[i-p(b)][b-1];
            }
        }
    cout << dp[x][31] << endl;
}