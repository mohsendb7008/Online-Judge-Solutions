#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, c, dp[maxn][3];
vector<int> adj[maxn];

int cdp(int u, int take){
    if(dp[u][take] != -1){
        return dp[u][take];
    }
    dp[u][take] = 0;
    int sum = 0;
    for(int v : adj[u]){
        dp[u][take] += cdp(v, 1);
        sum += cdp(v, 1);
    }
    if(take){
        for(int v : adj[u]){
            dp[u][take] = max(dp[u][take], sum - cdp(v, 1) + cdp(v, 0) + 1);
        }
    }
    return dp[u][take];
}

int main(){
    cin >> n >> c;
    if(c == 1){
        cout << n << endl;
        return 0;
    }
    if(c >= 3){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        int par;
        cin >> par;
        par--;
        adj[par].push_back(i);
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = dp[i][1] = -1;
    }
    cout << cdp(0, 1) << endl;
}