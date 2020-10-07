#include <bits/stdc++.h>
using namespace std;

// Fibonacci Tour

#define num long long int

vector<num> fib;
map<num, num> mp;

const int maxn = 1e5 + 3;

int n, m, dp[maxn];
num a[maxn];
bool one[maxn];
vector<int> adj[maxn];

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    int ans = one[u] ? 2 : 1;
    for(int v : adj[u])
        ans = max(ans, (one[u] ? 2 : 1) + cdp(v));
    return dp[u] = ans;
}

int main(){
    fib.push_back(1), fib.push_back(1);
    while(1){
        num f = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(f);
        if(f == 679891637638612258ll)
            break;
    }
    for(int i = 1; i < fib.size() - 1; i++)
        mp[fib[i]] = fib[i+1];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int x, y;
    while(m--){
        cin >> x >> y, x--, y--;
        if(a[x] == 1 && a[y] == 1)
            one[x] = one[y] = true;
        if(mp[a[x]] == a[y])
            adj[x].push_back(y);
        if(mp[a[y]] == a[x])
            adj[y].push_back(x);
    }
    int ans = 0;
    fill_n(dp, n, -1);
    for(int i = 0; i < n; i++){
        if(mp[a[i]])
            ans = max(ans, cdp(i));
        else if(a[i] == 679891637638612258ll)
            ans = max(ans, 1);
    }
    cout << ans << endl;
}