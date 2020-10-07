#include <bits/stdc++.h>
using namespace std;

// Single source shortest path, safe path

#define inf INT_MAX

int n, s, t, k;
vector<pair<int, int>> adj[1003];
int dp[1003][33];

int main(){
    int hkjhmdkgjskgj;
    cin >> hkjhmdkgjskgj;
    while(hkjhmdkgjskgj--){
        cin >> n;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            int d, j, w;
            cin >> d;
            while(d--)
                cin >> j >> w, adj[i].push_back({j, w});
        }
        int q;
        cin >> q;
        while(q--){
            cin >> s >> t >> k;
            for(int j = 0; j < k; j++)
                for(int i = 0; i < n; i++){
                    if(j){
                        dp[i][j] = (i == t) ? 0 : inf;
                        for(pair<int, int> k : adj[i])
                            if(dp[k.first][j-1] != inf)
                                dp[i][j] = min(dp[i][j], dp[k.first][j-1] + k.second);
                    }
                    else
                        dp[i][j] = (i == t) ? 0 : inf;
                }
            cout << (dp[s][k-1] == inf ? -1 : dp[s][k-1]) << endl;
        }
        cout << endl;
    }
}