#include <bits/stdc++.h>
using namespace std;

// Railway

const int maxn = 5e4 + 3;

int n, m, k, par[maxn], vis[maxn];
vector<int> adj[maxn];
map<pair<int, int>, int> id, cnt;
 
int main(){
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y, x--, y--;
        adj[x].push_back(y), adj[y].push_back(x);
        id[{x, y}] = i, cnt[{x, y}] = 0;
    }

}