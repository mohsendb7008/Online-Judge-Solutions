#include <bits/stdc++.h>
using namespace std;

// Succession

int cnt = 0;
map<string, int> id;
inline int gid(string s){
    if(id.find(s) != id.end())
        return id[s];
    return id[s] = cnt++;
}

vector<int> adj[153];
double dp[153];

double cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    double ans = 0;
    for(int v : adj[u])
        ans += cdp(v);
    return dp[u] = ans / 2;
}


int main(){
    int n, m;
    cin >> n >> m;
    string c, x, y;
    cin >> c;
    int f = gid(c);
    while(n--)
        cin >> c >> x >> y, adj[gid(c)].push_back(gid(x)), adj[gid(c)].push_back(gid(y));
    for(int i = 0; i < cnt; i++)
        dp[i] = i == f ? 1 : -1;
    double best = INT_MIN;
    string ans;
    while(m--){
        cin >> c;
        double sub = cdp(gid(c));
        if(sub > best)
            best = sub, ans = c;
    }
    cout << ans << endl;
}