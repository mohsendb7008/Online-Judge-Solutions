#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, adj[maxn], indeg[maxn], vis[maxn];
queue<int> kahn;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> adj[i], adj[i]--, indeg[adj[i]]++;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push(i);
    int ans = n;
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop(), vis[u] = 1, ans--;
        indeg[adj[u]]--;
        if(!indeg[adj[u]])
            kahn.push(adj[u]);
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        if(!vis[i])
            cout << i + 1 << " ";
    cout << endl;
}