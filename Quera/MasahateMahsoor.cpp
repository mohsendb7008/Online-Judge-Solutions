#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;

int n, par[maxn], ran[maxn], setsize[maxn], vis[maxn], maxsetsize = 1;
pair<num, int> h[maxn];

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));
}

inline void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j])
        par[j] = i, setsize[i] += setsize[j], maxsetsize = max(maxsetsize, setsize[i]);
    else
        par[i] = j, setsize[j] += setsize[i], maxsetsize = max(maxsetsize, setsize[j]);
    if(ran[i] == ran[j])
        ran[j]++;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i].first, h[i].second = i;
    sort(h, h + n);
    iota(par, par + n, 0);
    fill_n(setsize, n, 1);
    num ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(h[i].first * n <= ans)
            break;
        int u = h[i].second;
        vis[u] = 1;
        if(u + 1 < n && vis[u + 1])
            umerge(u, u + 1);
        if(u && vis[u - 1])
            umerge(u, u - 1);
        ans = max(ans, h[i].first * maxsetsize);
    }
    cout << ans << endl;
}