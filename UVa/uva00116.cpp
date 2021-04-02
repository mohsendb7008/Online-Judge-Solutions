#include <bits/stdc++.h>
using namespace std;

// Unidirectional TSP

int n, m;
int w[13][103];
int dp[13][103];
int trace[13][103];

vector<int> path;

int main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> w[i][j];
        for(int i = 0; i < n; i++)
            dp[i][m-1] = w[i][m-1];
        for(int j = m - 2; j >= 0; j--)
            for(int i = 0; i < n; i++){
                int r1 = (i - 1 + n) % n;
                int r2 = i;
                int r3 = (i + 1) % n;
                dp[i][j] = dp[r1][j+1];
                trace[i][j] = r1;
                if(dp[r2][j+1] < dp[i][j]){
                    dp[i][j] = dp[r2][j+1];
                    trace[i][j] = r2;
                }
                if(dp[r2][j+1] == dp[i][j] && r2 < trace[i][j])
                    trace[i][j] = r2;
                if(dp[r3][j+1] < dp[i][j]){
                    dp[i][j] = dp[r3][j+1];
                    trace[i][j] = r3;
                }
                if(dp[r3][j+1] == dp[i][j] && r3 < trace[i][j])
                    trace[i][j] = r3;
                dp[i][j] += w[i][j];
            }
        int it = 0;
        int ans = dp[0][0];
        for(int i = 1; i < n; i++)
            if(dp[i][0] < ans){
                it = i;
                ans = dp[i][0];
            }
        path.clear();
        for(int j = 0; j < m; j++){
            path.push_back(it);
            it = trace[it][j];
        }
        for(int i = 0; i < m; i++)
            cout << path[i] + 1 <<  (i == m-1 ? "\n" : " ");
        cout << ans << endl;
    }
}