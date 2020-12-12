#include <bits/stdc++.h>
using namespace std;

// Social Advertising

int n;
vector<int> adjs[23];

int dp[(1 << 20) + 3];

int cdp(int mask){
    if(dp[mask] != -1)
        return dp[mask];
    if(mask == 0)
        return dp[mask] = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int tmp = mask;
        if(tmp & (1 << i))
            tmp -= (1 << i);
        for(int x : adjs[i])
            if(tmp & (1 << x))
                tmp -= (1 << x);
        if(tmp != mask)
            ans = min(ans, 1 + cdp(tmp));
    }
    return dp[mask] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            adjs[i].clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            while(x--){
                int y;
                cin >> y;
                y--;
                adjs[i].push_back(y);
            }
        }
        int mask = (1 << n) - 1;
        fill_n(dp, (1 << n), -1);
        cout << cdp(mask) << endl;
    }
}