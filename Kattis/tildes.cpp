#include <bits/stdc++.h>
using namespace std;

// Tildes

const int maxn = 1e6 + 3;

int n, q, par[maxn], ran[maxn], siz[maxn];

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j]){
        par[j] = i;
        siz[i] += siz[j];
    }
    else{
        par[i] = j;
        siz[j] += siz[i];
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n >> q;
    iota(par, par + n, 0), fill_n(siz, n, 1);
    char t;
    int x, y;
    while(q--){
        cin >> t;
        if(t == 't')
            cin >> x >> y, umerge(x-1, y-1);
        else
            cin >> x, cout << siz[ufind(x-1)] << endl;
    }
}