#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

long long int n;
vector<int> adj[maxn];

int diameter = -1, farest;

void dfs(int u, int p, int h){
    if(h > diameter)
        diameter = h, farest = u;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, h + 1);
}

int main(){
    int x, y;
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y, x--, y--, adj[x].push_back(y), adj[y].push_back(x);
    dfs(0, -1, 0);
    dfs(farest, -1, 0);
    cout << diameter << " " << (n * (n - 1)) / 2 << endl;
}