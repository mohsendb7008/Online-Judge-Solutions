#include <bits/stdc++.h>
using namespace std;

// Bundles of Joy

const int maxm = 153;

int n, m = 0, price[maxm], par[maxm], dp[maxm];
set<int> items[maxm], tmp;
vector<int> adj[maxm];

int cdp(int i){
    if(dp[i] != -1)
        return dp[i];
    if(adj[i].empty())
        return dp[i] = price[i];
    dp[i] = price[i];
    int size = 0;
    for(int j : adj[i])
        size += items[j].size();
    if(size != items[i].size())
        return dp[i];
    int sum = 0;
    for(int j : adj[i])
        sum += cdp(j);
    return dp[i] = min(dp[i], sum);
}

int main(){
    int t, f, p, s, x;
    cin >> t;
    while(t--){
        cin >> n >> f;
        m = 0;
        while(f--){
            cin >> p >> s;
            tmp.clear();
            while(s--)
                cin >> x, tmp.insert(x);
            bool found = false;
            for(int i = 0; i < m; i++)
                if(items[i] == tmp){
                    price[i] = min(price[i], p);
                    found = true;
                    break;
                }
            if(!found)
                par[m] = -1, dp[m] = -1, price[m] = p, items[m] = tmp, adj[m++].clear();
        }
        for(int i = 0; i < m; i++){
            int psize = INT_MAX, p;
            for(int j = 0; j < m; j++)
                if(j != i){
                    tmp.clear();
                    set_difference(items[i].begin(), items[i].end(), items[j].begin(), items[j].end(), inserter(tmp, tmp.begin()));
                    if(tmp.empty() && items[j].size() < psize)
                        psize = items[j].size(), p = j;
                }
            if(psize != INT_MAX)
                par[i] = p, adj[p].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
            if(par[i] == -1)
                ans += cdp(i);
        cout << ans << endl;       
    }
}