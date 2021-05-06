#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num inf = LLONG_MAX;

const int maxnm = 500 * 500 + 3;

int n, m, k;

inline int encode(int i, int j){
    return i * m + j;
}

vector<pair<int, num>> adj[maxnm];

inline void connect(int i, int j, int p, int q, num w){
    int u = encode(i, j);
    int v = encode(p, q);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

num dp[maxnm][13];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m-1; j++){
            num w;
            cin >> w;
            connect(i, j, i, j + 1, w);
        }
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < m; j++){
            num w;
            cin >> w;
            connect(i, j, i + 1, j, w);
        }
    if(k % 2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << -1 << ' ';
            cout << '\n';
        }
        return 0;
    }
    k /= 2;
    for(int p = 1; p <= k; p++)
        for(int u = 0; u < n * m; u++){
            dp[u][p] = inf;
            for(auto v : adj[u])
                if(dp[v.first][p-1] != inf)
                    dp[u][p] = min(dp[u][p], dp[v.first][p-1] + v.second);
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << 2 * dp[encode(i, j)][k] << ' ';
        cout << '\n';
    }
}