#include <bits/stdc++.h>
using namespace std;

// Kingpin Escape

const int maxn = 1e5 + 3;

int n, r;
vector<int> adj[maxn];
vector<int> leaves;

void dfs(int u, int p){
    if(adj[u].size() == 1)
        leaves.push_back(u);
    for(int v : adj[u])
        if(v != p)
            dfs(v, u);
}

int main(){
    int x, y;
    cin >> n >> r;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    dfs(r, -1);
    cout << leaves.size() / 2 + leaves.size() % 2 << endl;
    for(int i = 0; i < leaves.size() / 2; i++)
        cout << leaves[i] << " " << leaves[i + leaves.size() / 2] << endl;
    if(leaves.size() % 2)
        cout << leaves[leaves.size()-1] << " " << leaves[0] << endl;
}