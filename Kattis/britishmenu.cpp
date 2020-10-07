#include <bits/stdc++.h>
using namespace std;

// British Menu

const int maxn = 1e5 + 3;

int n, m;
map<int, int> adj[maxn];

inline void connect(int u, int v, int w){
    if(adj[u].find(v) == adj[u].end())
        adj[u][v] = w;
    else if(adj[u][v] < w)
        adj[u][v] = w;
}

int cnt = 1, dfsn[maxn], dfsl[maxn];
bool vis[maxn];
stack<int> scc;
vector<vector<int>> sccs;

void dfs(int u){
    dfsn[u] = dfsl[u] = cnt++;
    vis[u] = 1;
    scc.push(u);
    for(pair<int, int> v : adj[u]){
        if(!dfsn[v.first])
            dfs(v.first);
        if(vis[v.first])
            dfsl[u] = min(dfsl[u], dfsl[v.first]);
    }
    if(dfsl[u] == dfsn[u]){
        vector<int> tmp;
        while(1){
            int v = scc.top();
            scc.pop();
            vis[v] = 0;
            tmp.push_back(v);
            if(v == u)
                break;
        }
        sccs.push_back(tmp);
    }
}

int k;
vector<int> tmp;
vector<vector<int>> paths;

void track(int i, vector<int> & nodes){
    if(i == k){
        paths.push_back(tmp);
        return;
    }
    for(int u : nodes)
        if(find(tmp.begin(), tmp.end(), u) == tmp.end()){
            if(!tmp.empty()){
                int z = tmp[tmp.size()-1];
                if(adj[z].find(u) == adj[z].end())
                    continue;
            }
            tmp.push_back(u);
            track(i+1, nodes);
            tmp.pop_back();
        }
}

vector<pair<int, pair<int, int>>> nedge;
int base[maxn];

void make(vector<int> & scc){
    paths.clear();
    for(k = 2; k <= scc.size(); k++)
        track(0, scc);
    for(vector<int> path : paths){
        int u = path[0], v = path[path.size()-1], w = path.size();
        base[u] = max(base[u], w);
        for(pair<int, int> z : adj[v])
            if(dfsl[z.first] != dfsl[u])
                nedge.push_back({u, {z.first, w}});
    }
}

int dp[maxn];

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    dp[u] = base[u];
    for(pair<int, int> v : adj[u])
        if(dfsl[u] != dfsl[v.first])
            dp[u] = max(dp[u], v.second + cdp(v.first));
    return dp[u];
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x-1][y-1] = 1;
    for(int i = 0; i < n; i++)
        if(!dfsn[i])
            dfs(i); 
    int id = 0;
    for(vector<int> scc : sccs){
        for(int u : scc)
            dfsl[u] = id;
        id++;
    }
    fill_n(base, n, 1);
    for(vector<int> scc : sccs)
        make(scc);
    for(auto e : nedge)
        connect(e.first, e.second.first, e.second.second);
    fill_n(dp, n, -1);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, cdp(i));
    cout << ans << endl;
}