#include <bits/stdc++.h>
using namespace std;

// Brexit Negotiations

int n, d, x;
int e[400003];
int indeg[400003];
vector<int> adj[400003];
int memo[400003];

int rec(int node){
    if(memo[node] != -1)
        return memo[node];
    int ans = e[node];
    for(int child : adj[node])
        ans = max(ans, rec(child));
    return memo[node] = ans;
}

priority_queue<pair<int, int>> kahn;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        memo[i] = -1;
        cin >> e[i];
        cin >> indeg[i];
        d = indeg[i];
        while(d--){
            cin >> x;
            adj[x-1].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
        rec(i);
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push({memo[i], i});
    int cnt = 0, ans = 0;
    while(!kahn.empty()){
        pair<int, int> u = kahn.top();
        kahn.pop();
        ans = max(ans, u.first + cnt++);
        for(int v : adj[u.second]){
            indeg[v]--;
            if(!indeg[v])
                kahn.push({memo[v], v});
        }
    }
    cout << ans << endl;
}