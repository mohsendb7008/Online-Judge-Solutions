#include <bits/stdc++.h>
using namespace std;

// Political Development

const int maxn = 5e4 + 3;

int n, k, deg[maxn];
vector<int> adj[maxn], adj2[maxn];

map<int, int> shrink, boost;
bool dp[(1 << 9) + 3];

inline int clique(int source){
    int ans = 0, V = adj2[source].size(), cnt = 0;
    shrink.clear(), boost.clear();
    for(int u : adj2[source])
        shrink[u] = cnt, boost[cnt++] = u;
    for(int mask = 1; mask < (1 << V); mask++){
        dp[mask] = false;
        int cp = mask, cnt = 0;
        while(cp){
            if(cp % 2)
                cnt++;
            cp /= 2;
        }
        if(cnt == 1)
            dp[mask] = true, ans = max(ans, 1);
        else{
            for(int i = 0; i < V; i++)
                if(mask & (1 << i)){
                    int subp = mask - (1 << i);
                    if(!dp[subp])
                        continue;
                    int u = boost[i], validate = 0;
                    for(int v : adj2[u])
                        if(shrink.find(v) != shrink.end() && (mask & (1 << shrink[v])))
                            validate += (1 << shrink[v]);
                    if(validate == subp){
                        dp[mask] = true, ans = max(ans, cnt);
                        break;
                    }
                }
        }
    }
    return ans;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> order;
bool taken[maxn];
int pos[maxn];

int main(){
    cin >> n >> k;
    for(int u = 0; u < n; u++){
        cin >> deg[u];
        int v;
        for(int i = 0; i < deg[u]; i++)
            cin >> v, adj[u].push_back(v);
        pq.push({deg[u], u});
    }
    while(!pq.empty()){
        int u = pq.top().second, mdeg = pq.top().first;
        pq.pop();
        if(taken[u])
            continue;
        if(mdeg >= k)
            break;
        order.push_back(u);
        taken[u] = true;
        for(int v : adj[u]){
            if(taken[v])
                continue;
            deg[v]--;
            pq.push({deg[v], v});
        }
    }
    for(int i = 0; i < order.size(); i++)
        pos[order[i]] = i + 1;
    for(int u = 0 ; u < n; u++)
        for(int v : adj[u])
            if(pos[u] < pos[v])
                adj2[u].push_back(v);
    int ans = 1;
    for(int u : order){
        ans = max(ans, clique(u) + 1);
        if(ans == k)
            break;
    }
    cout << ans << endl;
}