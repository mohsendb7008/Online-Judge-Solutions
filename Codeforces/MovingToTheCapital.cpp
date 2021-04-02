#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, m, d[maxn], dp[maxn][3];
vector<int> adj[maxn];
queue<int> bfs;

int cdp(int u, int mistake){
    if(dp[u][mistake] != -1)
        return dp[u][mistake];
    int ans = d[u];
    for(int v : adj[u]){
        if(d[v] > d[u])
            ans = min(ans, cdp(v, mistake));
        else if(mistake)
            ans = min(ans, cdp(v, 0));
    }
    return dp[u][mistake] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int u, v;
        while(m--)
            cin >> u >> v, adj[u - 1].push_back(v - 1);
        fill_n(d, n, -1);
        d[0] = 0;
        bfs.push(0);
        while(!bfs.empty()){
            int u = bfs.front();
            bfs.pop();
            for(int v : adj[u])
                if(d[v] == -1)
                    d[v] = d[u] + 1, bfs.push(v);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2; j++)
                dp[i][j] = -1;
        for(int i = 0; i < n; i++)
            cout << cdp(i, 1) << " ";
        cout << endl;
    }
}
