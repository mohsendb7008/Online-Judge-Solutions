#include <bits/stdc++.h>
using namespace std;

// Rainbow Roads

int n;
vector<pair<int, int>> adj[50003];
bool possible = true, good[50003];

// dfs on tree does not require vis array! just take care of parent adjacent.

void dfsr(int u, int p, int c){
    good[u] = false;
    for(auto v : adj[u])
        if(v.first != p){
            if(c == v.second)
                possible = false;
            dfsr(v.first, u, v.second);
        }
}

void dfs(int u, int p){
    map<int, vector<int>> colors;
    for(auto v : adj[u])
        colors[v.second].push_back(v.first);
    for(auto c : colors){
        if(c.second.size() >= 2)
            for(int v : c.second)
                dfsr(v, u, c.first);
        else if(c.second[0] != p)
            dfs(c.second[0], u);
    }
}


int main(){
    cin >> n;
    fill_n(good, n, true);
    int x, y, c;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y >> c, adj[x-1].push_back({y-1, c}), adj[y-1].push_back({x-1, c});
    for(int i = 0; i < n; i++){
        map<int, int> colors;
        for(auto v : adj[i])
            colors[v.second]++;
        bool cand = false;
        for(auto c : colors)
            if(c.second >= 2){
                cand = true;
                break;
            }
        if(cand){
            dfs(i, -1);
            break;
        }
    }
    if(!possible){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++)
        if(good[i])
            ans.push_back(i+1);
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << endl;
}