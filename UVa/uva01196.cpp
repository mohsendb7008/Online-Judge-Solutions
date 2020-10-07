#include <bits/stdc++.h>
using namespace std;

// Tiling Up Blocks

pair<int, int> blocks[10003];
int dp[10003];

int main(){
    while(1196){
        int n;
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> blocks[i].first >> blocks[i].second;
        sort(blocks, blocks+n);
        for(int i = n-1; i >= 0; i--){
            dp[i] = 1;
            for(int j = i+1; j < n; j++)
                if(blocks[i].second <= blocks[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        int ans = dp[0];
        for(int i = 1; i < n; i++)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    cout << "*" << endl;
}