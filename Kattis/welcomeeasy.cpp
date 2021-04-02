#include <bits/stdc++.h>
using namespace std;

// Welcome to Code Jam (Easy)

string s1 = "welcome to code jam", s2;
int dp[23][33];

int cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == s1.size())
        return dp[i][j] = 1;
    if(j == s2.size())
        return dp[i][j] = 0;
    int ans = cdp(i, j+1);
    if(s1[i] == s2[j])
        ans = (ans + cdp(i+1, j+1)) % 10000;
    return dp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    getline(cin, s2);
    for(int test = 1; test <= t; test++){
        getline(cin, s2);
        for(int i = 0; i < 23; i++)
            for(int j = 0; j < 33; j++)
                dp[i][j] = -1;
        printf("Case #%d: %04d\n", test, cdp(0, 0));   
    }
}