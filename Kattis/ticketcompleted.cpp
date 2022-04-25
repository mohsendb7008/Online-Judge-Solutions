#include <bits/stdc++.h>
using namespace std;

// Ticket Completed?

#define num long long int

inline num C2(num n){
    return n * (n - 1) / 2;
}

const int maxn = 1e5 + 3;

int n, m, vis[maxn], ccSize;
vector<int> adj[maxn];

void dfs(int u){
    vis[u] = 1;
    ccSize++;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    num ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ccSize = 0;
            dfs(i);
            ans += C2(ccSize);
        }
    }
    cout << fixed << setprecision(10) << double(ans) / C2(n) << endl;
}