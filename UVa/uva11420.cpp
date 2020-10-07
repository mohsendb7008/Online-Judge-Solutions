#include <bits/stdc++.h>
using namespace std;

// Chest of Drawers

#define num long long int

num dp[68][68][3];

num cdp(int n, int s, bool o){
    if(s > n)
        return 0;
    if(n == 0)
        return s == 0;
    if(dp[n][s][o] != -1)
        return dp[n][s][o];
    return dp[n][s][o] = cdp(n-1, s, true) + cdp(n-1, o ? s : s-1, false); 
}

int main(){
    for(int i = 0; i < 68; i++)
        for(int j = 0; j < 68; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    int n, s;
    while(1){
        cin >> n >> s;
        if(n + s < 0)
            break;
        cout << cdp(n, s, false) << endl;
    }
}