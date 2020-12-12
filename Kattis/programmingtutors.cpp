#include <bits/stdc++.h>
using namespace std;

// Programming Tutors

int n, xstu[103], ystu[103], xtuto[103], ytuto[103], match[103], vis[103];
vector<int> adj[103];

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
            if(abs(xstu[i] - xtuto[j]) + abs(ystu[i] - ytuto[j]) <= k)
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
        cin >> xstu[i] >> ystu[i];
    for(int i = 0; i < n; i++)
        cin >> xtuto[i] >> ytuto[i];
    int lo = 0, hi = 400000000;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}