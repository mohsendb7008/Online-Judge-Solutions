#include <bits/stdc++.h>
using namespace std;

// RA Duty Scheduler

int m, n, s, t, c[93][93], flow[93][93], par[93];
string names[63];
vector<int> adj[93];

int augment(){
    fill_n(par, n + m + 2, -1);
    par[s] = -2;
    queue<pair<int, int>> bfs;
    bfs.push({s, INT_MAX});
    while(!bfs.empty()){
        int u = bfs.front().first, f = bfs.front().second;
        bfs.pop();
        if(u == t)
            return f;
        for(int v : adj[u])
            if(par[v] == -1 && c[u][v] - flow[u][v] > 0)
                par[v] = u, bfs.push({v, min(f, c[u][v] - flow[u][v])});
    }
    return 0;
}

int maxflow(){
    int ans = 0;
    while(1){
        int f = augment();
        if(!f)
            break;
        int it = t;
        while(it != s){
            flow[par[it]][it] += f;
            flow[it][par[it]] -= f;
            it = par[it];
        }
        ans += f;
    }
    return ans;
}

vector<string> assig[33];

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> names[i];
        int d, x;
        cin >> d;
        while(d--)
            cin >> x, x--, adj[i].push_back(m + x), adj[m + x].push_back(i), c[i][m + x] = 1;
    }
    s = m + n, t = m + n + 1;
    for(int i = 0; i < m; i++)
        adj[s].push_back(i), adj[i].push_back(s);
    for(int i = m; i < m + n; i++)
        adj[i].push_back(t), adj[t].push_back(i), c[i][t] = 2;
    for(int ans = 1; 1; ans++){
        for(int i = 0; i <= t; i++)
            for(int j = 0; j <= t; j++)
                flow[i][j] = 0;
        for(int i = 0; i < m; i++)
            c[s][i] = ans;
        int mf = maxflow();
        if(mf == 2 * n){
            cout << ans << endl;
            for(int i = 0; i < m; i++)
                for(int j = m; j < m + n; j++)
                    if(flow[i][j] == 1)
                        assig[j - m].push_back(names[i]);
            for(int i = 0; i < n; i++)
                cout << "Day " << i + 1 << ": " << assig[i][0] << " " << assig[i][1] << endl;
            break;
        }
    }
}