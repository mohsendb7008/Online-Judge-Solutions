#include <bits/stdc++.h>
using namespace std;

// Flipping Cards

const int maxn = 1e5 + 3;

int m, n, par[maxn], ran[maxn];
pair<int, int> edges[maxn];
bool cycle[maxn];
map<int, int> cnt;

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

int umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return i;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
    return -1;
}

int main(){
    int t, x, y;
    cin >> t;
    while(t--){
        cin >> m, n = 2 * m;
        iota(par, par + n, 0);
        fill_n(ran, n, 0);
        fill_n(cycle, m, false);
        for(int i = 0; i < m; i++){
            cin >> edges[i].first >> edges[i].second, edges[i].first--, edges[i].second--;
            if(umerge(edges[i].first, edges[i].second) != -1)
                cycle[i] = true;
        }
        cnt.clear();
        for(int i = 0; i < m; i++)
            if(cycle[i])
                cnt[umerge(edges[i].first, edges[i].second)]++;
        bool ans = true;
        for(pair<int, int> k : cnt)
            if(k.second >= 2){
                ans = false;
                break;
            }
        cout << (ans ? "possible" : "impossible") << endl;
    }
}