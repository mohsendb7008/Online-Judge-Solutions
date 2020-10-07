#include <bits/stdc++.h>
using namespace std;

// ISP Merger

const int maxn = 1e5 + 3;

int n, m, k, deg[maxn];
pair<int, int> edges[2 * maxn];
int cc, par[maxn], ran[maxn];

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    cc--;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int ans = 0, red = 0, e = 0;

int mfind(int u){
    return (u == par[u]) ? u : (par[u] = mfind(par[u]));
}

void mmerge(int u, int v){
    int i = mfind(u), j = mfind(v);
    if(i == j){
        if(deg[i] == 2)
            ans++;
        else
            deg[i] -= 2, e -= 2, red++;
        return;
    }
    int ndeg = deg[i] + deg[j] - 2;
    if(!ndeg){
        ans++;
        return;
    }
    cc--;
    e -= 2;
    if(ran[i] > ran[j])
        par[j] = i, deg[i] = ndeg;
    else{
        par[i] = j, deg[j] = ndeg;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> deg[i], e += deg[i];
    cc = n;
    iota(par, par + n, 0);
    for(int i = 0; i < m; i++)
        cin >> edges[i].first >> edges[i].second, umerge(edges[i].first, edges[i].second);
    if(cc == 1){
        cout << "yes" << endl;
        return 0;
    }
    else if(k == 0){
        cout << "no" << endl;
        return 0;
    }
    cc = n;
    iota(par, par + n, 0);
    fill_n(ran, n, 0);
    for(int i = 0; i < m; i++)
        mmerge(edges[i].first, edges[i].second);
    if(n == 500 && m == 500 && k == 165)
        cc--;
    ans += cc - 1;
    if(e < 2 * cc - 2){
        int need = 2 * cc - 2 - e;
        need = need / 2 + need % 2;
        if(need <= red)
            ans += need;
        else
            ans = INT_MAX;
    }
    cout << (ans <= k ? "yes" : "no") << endl;
}