#include <bits/stdc++.h>
using namespace std;

// Book Club

int n, m, match[10003];
bool vis[10003];
vector<int> adj[10003];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = true;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x].push_back(y);
    fill_n(match, n, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, false), mcbm += augment(i);
    cout << (mcbm == n ? "YES" : "NO") << endl;
}