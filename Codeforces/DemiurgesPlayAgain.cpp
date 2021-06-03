#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, leaves[maxn], dp[maxn];
vector<int> childs[maxn];

int cleaves(int u){
    if(leaves[u] != -1)
        return leaves[u];
    if(childs[u].empty())
        return leaves[u] = 1;
    int sum = 0;
    for(int v : childs[u])
        sum += cleaves(v);
    return leaves[u] = sum;
}

int cdp1(int u, int who){
    if(dp[u] != -1)
        return dp[u];
    if(childs[u].empty())
        return dp[u] = 1;
    int ans = 0;
    if(who){
        int leaves = cleaves(u);
        for(int v : childs[u])
            ans = max(ans, leaves - cleaves(v) + cdp1(v, 1 - who));
    }
    else{
        for(int v : childs[u])
            ans += cdp1(v, 1 - who) - 1;
        ans++;
    }
    return dp[u] = ans;
}

int cdp2(int u, int who){
    if(dp[u] != -1)
        return dp[u];
    if(childs[u].empty())
        return dp[u] = 1;
    int ans = 0;
    if(who){
        for(int v : childs[u])
            ans += cdp2(v, 1 - who);
    }
    else{
        ans = INT_MAX;
        for(int v : childs[u])
            ans = min(ans, cdp2(v, 1 - who));
    }
    return dp[u] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        childs[u].push_back(v);        
    }
    for(int i = 0; i < n; i++)
        leaves[i] = dp[i] = -1;
    cout << cdp1(0, 1) << ' ';
    for(int i = 0; i < n; i++)
        dp[i] = -1;
    cout << cdp2(0, 1) << '\n';
}