#include <bits/stdc++.h>
using namespace std;

// Keyboards In Concert

int n, m;
set<int> notes[1003];
int a[1003];
int dp[1003][1003];

int cdp(int i, int k){
    if(i == m)
        return 0;
    if(dp[i][k] != -1)
        return dp[i][k];
    if(notes[a[i]].find(k) != notes[a[i]].end())
        return dp[i][k] = cdp(i + 1, k);
    int ans = INT_MAX;
    for(int k : notes[a[i]])
        ans = min(ans, cdp(i + 1, k) + 1);
    return dp[i][k] = ans;
}

int main(){
    for(int i = 0; i < 1003; i++)
        for(int j = 0; j < 1003; j++)
            dp[i][j] = -1;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            notes[x].insert(i);
        }
    }
    for(int i = 0; i < m; i++)
        cin >> a[i];
    int ans = INT_MAX;
    for(int k : notes[a[0]])
        ans = min(ans, cdp(1, k));
    cout << ans << endl;
}