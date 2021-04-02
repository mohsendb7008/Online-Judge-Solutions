#include<bits/stdc++.h>
using namespace std;

// Proteins

string p;

int dp[1003][1003];

int cdp(int i, int k){
    if(i == -1)
        return k*3;
    if(k == 0){
        if((i+1)%3==1)
            return 2;
        if((i+1)%3==2)
            return 1;
        return 0;
    }
    if(dp[i][k] != -1)
        return dp[i][k];
    int ans = INT_MAX;
    if(i >= 0){
        if(p[i] != 'C')
            ans = min(ans, 2 + cdp(i-1, k-1));
        ans = min(ans, (i==p.size()-1?0:2) + cdp(i-1, k));
    }
    if(i >= 1){
        string s = p.substr(i-1, 2);
        if(s == "AT" || s == "AG" || s == "TG")
            ans = min(ans, 1 + cdp(i-2, k-1));
        ans = min(ans, (i==p.size()-1?0:1) + cdp(i-2, k));
    }
    if(i >= 2){
        if(p.substr(i-2, 3) == "ATG")
            ans = min(ans, cdp(i-3, k-1));
        else ans = min(ans, cdp(i-3, k));
    }
    return dp[i][k] = ans;
}


int main(){
    for(int i=0; i < 1003; i++)
        for(int j=0; j < 1003; j++)
            dp[i][j] = -1;
    int n;
    cin >> n;
    cin >> p;
    int need = min(n, int(p.size()));
    cout << max(n-need, 0)*3 + cdp(p.size()-1, need) << endl;
}