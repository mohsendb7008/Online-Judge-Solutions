#include <bits/stdc++.h>
using namespace std;

// Frozen Rose-Heads

int n, r;
vector<pair<int, int>> adj[1003];

int cdp(int u, int p){
    if(adj[u].size() == 1 && adj[u][0].first == p)
        return INT_MAX;
    int ans = 0;
    for(pair<int, int> v : adj[u])
        if(v.first != p)
            ans += min(v.second, cdp(v.first, u));
    return ans;
}

int main(){
    while(cin >> n >> r){
        r--;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y, w;
        for(int i = 0; i < n-1; i++)
            cin >> x >> y >> w, x--, y--, adj[x].push_back({y, w}), adj[y].push_back({x, w});
        cout << cdp(r, -1) << endl;
    }   
}