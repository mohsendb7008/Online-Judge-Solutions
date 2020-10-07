#include <bits/stdc++.h>
using namespace std;

// Grid Game

int n, a[33][33], match[33], vis[33];
vector<int> adj[33];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

bool judge(int k){
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] >= k)
                adj[i].push_back(j);
    fill_n(match, n, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, 0), mcbm += augment(i);
    return mcbm == n;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    int lo = 1, hi = 1e6;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
}