#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 3;

int n, k, indeg[2 * maxn], outdeg[2 * maxn], vis[2 * maxn];
string s[maxn];
int cnt = 0;
unordered_map<string, int> id;
vector<pair<int, int>> adj[2 * maxn];
string ans = "";

inline int get_id(string t){
    auto it = id.find(t);
    if(it != id.end())
        return it->second;
    return id[t] = cnt++;
}

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u])
        if(!vis[v.first])
            dfs(v.first);
}

void euler(int u){
    while(!adj[u].empty()){
        auto x = *adj[u].rbegin();
        adj[u].pop_back();
        euler(x.first);
        ans.push_back(s[x.second][0]);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int u = get_id(s[i].substr(0, k-1));
        int v = get_id(s[i].substr(1, k-1));
        adj[u].push_back({v, i});
        outdeg[u]++, indeg[v]++;
    }
    for(int i = 0; i < cnt; i++){
        if(outdeg[i] != indeg[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    dfs(0);
    if(count(vis, vis + cnt, 1) != cnt){
        cout << -1 << endl;
        return 0;
    }
    euler(0);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}