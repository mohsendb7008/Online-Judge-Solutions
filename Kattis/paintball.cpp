#include <bits/stdc++.h>
using namespace std;

// Paintball

int n, m, match[1003], vis[1003], ans[1003];
vector<int> adj[1003];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l, ans[l] = r;
            return 1;
        }
    return 0;
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, x--, y--, adj[x].push_back(y), adj[y].push_back(x);
    fill_n(match, n, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, 0), mcbm += augment(i);
    if(mcbm != n){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << endl;
}