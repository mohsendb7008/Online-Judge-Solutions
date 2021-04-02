#include <bits/stdc++.h>
using namespace std;

// Highest Tower

const int maxn = 250003;

#define num long long int

int m, n = 0;
pair<num, num> rect[maxn];
map<num, int> id;
num a[2 * maxn];

vector<pair<int, int>> adj[2 * maxn];
int par[2 * maxn];
int c = 0, comp[2 * maxn];
pair<int, int> cycle[2 * maxn];
pair<num, int> max_node[2 * maxn];

void dfss(int u, int e){
    comp[u] = c;
    if(a[u] > max_node[c].first)
        max_node[c] = {a[u], u};
    for(pair<int, int> v : adj[u])
        if(v.second != e){
            if(comp[v.first] != -1){
                if(cycle[c] == make_pair(-1, -1))
                    cycle[c] = {u, v.first};
            }
            else
                par[v.first] = u, dfss(v.first, v.second);
        }
}

bool vis[2 * maxn];
num ans = 0;

void dfs(int u, int e){
    for(pair<int, int> v : adj[u]){
        if(vis[v.first] || v.second == e)
            continue;
        ans += a[u], dfs(v.first, v.second);
    }
}

vector<int> path;

int main(){
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> rect[i].first >> rect[i].second;
        if(id.find(rect[i].first) == id.end())
            id[rect[i].first] = n, a[n++] = rect[i].first;
        if(id.find(rect[i].second) == id.end())
            id[rect[i].second] = n, a[n++] = rect[i].second;
    }
    for(int i = 0; i < m; i++){
        int u = id[rect[i].first], v = id[rect[i].second];
        adj[u].push_back({v, i});
        if(v != u)
            adj[v].push_back({u, i});
    }
    fill_n(par, n, -1);
    fill_n(comp, n, -1);
    fill_n(cycle, n, make_pair(-1, -1));
    fill_n(max_node, n, make_pair(LLONG_MIN, -1));
    for(int i = 0; i < n; i++)
        if(comp[i] == -1)
            dfss(i, -1), c++;
    for(int i = 0; i < c; i++){
        if(cycle[i] == make_pair(-1, -1))
            dfs(max_node[i].second, -1);
        else{
            path.clear();
            int u = cycle[i].first, v = cycle[i].second;
            while(1){
                vis[u] = true;
                ans += a[u];
                path.push_back(u);
                if(u == v)
                    break;
                u = par[u];
            }
            for(int u : path)
                dfs(u, -1);
        }
    }
    cout << ans << endl;
}