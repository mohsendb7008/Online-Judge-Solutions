#include <bits/stdc++.h>
using namespace std;

// Minimum Spanning Tree

const int maxn = 2e5, maxm = 3e5;

int n, m, cnt, par[maxn + 3], ran[maxn + 3];
pair<int, pair<int, int>> edges[maxm + 3];
set<pair<int, int>> ans;

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

bool umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return false;
    cnt--;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
    return true;
}

int main(){
    while(1){
        cin >> n >> m;
        if(!(n + m))
            break;
        cnt = n;
        iota(par, par + n, 0);
        fill_n(ran, n, 0);
        for(int i = 0; i < m; i++)
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        sort(edges, edges + m);
        int mst = 0;
        ans.clear();
        for(int i = 0; i < m; i++)
            if(umerge(edges[i].second.first, edges[i].second.second))
                mst += edges[i].first, ans.insert({min(edges[i].second.first, edges[i].second.second), max(edges[i].second.first, edges[i].second.second)});
        if(cnt != 1)
            cout << "Impossible" << endl;
        else{
            cout << mst << endl;
            for(auto e : ans)
                cout << e.first << " " << e.second << endl;
        }
    }
}