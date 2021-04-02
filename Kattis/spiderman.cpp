#include <bits/stdc++.h>
using namespace std;

// Spiderman's Workout

int m;
int d[43];

int dp[43][1003];
char trace[43][1003];

int cdp(int i, int h){
    if(i == m)
        return h == 0 ? 0 : -2;
    if(dp[i][h] != -1)
        return dp[i][h];
    int ans = -2;
    int subp1 = cdp(i+1, h + d[i]);
    if(subp1 != -2){
        ans = subp1;
        trace[i][h] = 'U';
    }
    if(h - d[i] >= 0){
        int subp2 = cdp(i+1, h - d[i]);
        if(subp2 != -2)
            if(ans == -2 || subp2 < ans){
                ans = subp2;
                trace[i][h] = 'D';
            }
    }
    return dp[i][h] = ans == -2 ? -2 : max(h, ans);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> d[i];
        for(int i = 0; i < 43; i++)
            for(int j = 0; j < 1003; j++)
                dp[i][j] = -1;
        int ans = cdp(0, 0);
        if(ans == -2)
            cout << "IMPOSSIBLE" << endl;
        else{
            int hit = 0;
            for(int i = 0; i < m; i++){
                cout << trace[i][hit];
                if(trace[i][hit] == 'U')
                    hit += d[i];
                else hit -= d[i];
            }
            cout << endl;
        }
    }
}