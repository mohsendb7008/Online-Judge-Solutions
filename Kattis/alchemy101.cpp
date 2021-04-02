#include <bits/stdc++.h>
using namespace std;

// Alchemy 101

int dp[1024][1001], trace[1024][1001];

int main(){
    for(int i = 0; i <= 1000; i++)
        for(int s = 0; s < 1024; s++){
            if(!i)
                dp[s][i] = s ? -1 : 0;
            else{
                dp[s][i] = -1;
                if(dp[s][i-1] != -1)
                    dp[s][i] = dp[s][i-1];
                if(dp[s^i][i-1] != -1 && 1+dp[s^i][i-1] > dp[s][i])
                    dp[s][i] = dp[s^i][i-1]+1, trace[s][i] = 1; // pick it
            }
        }
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        cout << dp[m][m] << endl;
        vector<int> ans;
        int its = m, iti = m;
        while(iti){
            if(trace[its][iti])
                ans.push_back(iti), its ^= iti;
            iti--;
        }
        reverse(ans.begin(), ans.end());
        for(int it : ans)
            cout << it << " ";
        cout << endl;
    }
}