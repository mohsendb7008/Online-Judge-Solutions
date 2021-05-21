#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, blacks[1003], whites[1003], dp[1003][2];

int main(){
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '#')
                blacks[j]++;
            else
                whites[j]++;
        }
    for(int i = m-1; i >= 0; i--)
        for(int c = 0; c < 2; c++){
            dp[i][c] = INT_MAX;
            int cost = 0;
            for(int z = 1; z <= min(y, m - i); z++){
                if(c)
                    cost += blacks[i + z - 1];
                else
                    cost += whites[i + z - 1];
                if(z >= x && dp[i + z][1 - c] != INT_MAX)
                    dp[i][c] = min(dp[i][c], cost + dp[i + z][1 - c]);
            }
        }
    cout << min(dp[0][0], dp[0][1]) << endl;
}