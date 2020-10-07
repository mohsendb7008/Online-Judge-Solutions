#include <bits/stdc++.h>
using namespace std;

// The Marriage Interview ;-)

unsigned long long int dp[63][63];

unsigned long long int cdp(int n, int back){
    if(n <= 1)
        return 1;
    if(dp[n][back] != -1)
        return dp[n][back];
    unsigned long long int ans = 1;
    for(int i = 1; i <= back; i++)
        ans += cdp(n-i, back);
    return dp[n][back] = ans;
}

int main(){
    for(int i = 0; i < 63; i++)
        for(int j = 0; j < 63; j++)
            dp[i][j] = -1;
    int n, back;
    int c = 1;
    while(1){
        cin >> n >> back;
        if(n > 60)
            break;
        cout << "Case " << c++ << ": " << cdp(n, back) << endl;
    }
}