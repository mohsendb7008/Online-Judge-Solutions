#include <bits/stdc++.h>
using namespace std;

// Lost Map

const int maxn = 2503;

int n, m = 0, par[maxn], ran[maxn];
pair<int, pair<int, int>> edges[maxn * maxn];
vector<pair<int, int>> ans;

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    ans.push_back({u, v});
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n;
    iota(par, par + n, 0);
    int w;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> w;
            if(i < j)
                edges[m++] = {w, {i, j}};
        }
    sort(edges, edges + m);
    for(auto e : edges)
        umerge(e.second.first, e.second.second);
    for(auto e : ans)
        cout << e.first + 1 << " " << e.second + 1 << endl;
}