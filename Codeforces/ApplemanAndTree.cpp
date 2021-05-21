#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
const int mod = 1000000007;

int n, x[maxn];
vector<int> adj[maxn];

#define num long long int

num dp[maxn][3];

num ways(int u, int s){
    if(dp[u][s] != -1)
        return dp[u][s];
    num ans = 1;
    if(x[u] && !s){
        for(int v : adj[u])
            ans = (ans * ((ways(v, 0) + ways(v, 1)) % mod)) % mod;
    }
    else if(!x[u] && !s){
        vector<num> prefix, suffix;
        num part = 1;
        for(int v : adj[u]){
            part = (part * ((ways(v, 0) + ways(v, 1)) % mod)) % mod;
            prefix.push_back(part);
        }
        part = 1;
        for(auto it = adj[u].rbegin(); it != adj[u].rend(); it++){
            int v = *it;
            part = (part * ((ways(v, 0) + ways(v, 1)) % mod)) % mod;
            suffix.push_back(part);
        }
        reverse(suffix.begin(), suffix.end());
        ans = 0;
        for(int c = 0; c < adj[u].size(); c++){
            num mul = ways(adj[u][c], 0);
            if(c)
                mul = (mul * prefix[c-1]) % mod;
            if(c+1 < adj[u].size())
                mul = (mul * suffix[c+1]) % mod;
            ans = (ans + mul) % mod;
        }
    }
    else if(x[u] && s){
        ans = 0;
    }
    else if(!x[u] && s){
        for(int v : adj[u])
            ans = (ans * ((ways(v, 0) + ways(v, 1)) % mod)) % mod;
    }
    return dp[u][s] = ans;
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
    cout << ways(0, 0) << endl;
}