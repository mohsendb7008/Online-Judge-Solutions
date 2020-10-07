#include <bits/stdc++.h>
using namespace std;

// Bowser's Pipes

const int maxn = 1e5 + 3;

int n, adj[maxn], deg[maxn];
pair<int, int> dp[maxn];

pair<int, int> cdp(int i){
    if(dp[i] != make_pair(-1, -1))
        return dp[i];
    if(adj[i] == -1)
        return dp[i] = {0, i};
    pair<int, int> subp = cdp(adj[i]);
    return dp[i] = {1 + subp.first, subp.second};    
}

map<int, int> len, src;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> adj[i];
        if(adj[i] != -1)
            deg[adj[i]]++;
        else
            len[i] = INT_MAX;
        dp[i] = {-1, -1};
    }
    for(int i = 0; i < n; i++)
        if(!deg[i]){
            pair<int, int> ans = cdp(i);
            if(ans.first < len[ans.second])
                len[ans.second] = ans.first, src[ans.second] = i;   
        }
    int k, x;
    cin >> k;
    while(k--)
        cin >> x, cout << src[cdp(x).second] << endl;
}