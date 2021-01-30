#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m;
num grid[2003][2003], dp[2003][2003];
char trace[2003][2003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    dp[n-1][0] = grid[n-1][0];
    for(int j = 1; j < m; j++)
        dp[n-1][j] = dp[n-1][j-1] + grid[n-1][j], trace[n-1][j] = 'R';
    for(int i = n-2; i >= 0; i--)
        dp[i][0] = dp[i+1][0] + grid[i][0], trace[i][0] = 'U';
    for(int i = n-2; i >= 0; i--)
        for(int j = 1; j < m; j++){
            if(dp[i+1][j] > dp[i][j-1])
                dp[i][j] = dp[i+1][j] + grid[i][j], trace[i][j] = 'U';
            else
                dp[i][j] = dp[i][j-1] + grid[i][j], trace[i][j] = 'R';
        }
    cout << dp[0][m-1] << endl;
    string path = "";
    int iti = 0, itj = m-1;
    while(iti != n-1 || itj){
        path.push_back(trace[iti][itj]);
        if(path.back() == 'U')
            iti++;
        else
            itj--;
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
}