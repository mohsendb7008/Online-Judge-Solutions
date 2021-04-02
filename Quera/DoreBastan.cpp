#include <bits/stdc++.h>
using namespace std;

long long int dp[203];
char path[203];

int main(){
    int n;
    cin >>n;
    for(int i = 0; i < n; i++)
        cin >> path[i];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 0;
        if(path[i] != 'T'){
            if(i-1 >= 0)
                dp[i] += dp[i-1];
            if(i-2 >= 0)
                dp[i] += dp[i-2];
            if(i-3 >= 0)
                dp[i] += dp[i-3];
        }
    }
    cout << dp[n-1] << endl;
}