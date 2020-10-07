#include <bits/stdc++.h>
using namespace std;

// Ladice

const int maxn = 3e5 + 3;

int q, n, par[maxn], ran[maxn], siz[maxn], ite[maxn];

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));  
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j]){
        par[j] = i;
        siz[i] += siz[j];
        ite[i] += ite[j];
        siz[j] = ite[j] = 0;
    }
    else{
        par[i] = j;
        siz[j] += siz[i];
        ite[j] += ite[i];
        siz[i] = ite[i] = 0;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}


int main(){
    cin >> q >> n;
    iota(par, par + n, 0);
    fill_n(siz, n, 1);
    int x, y;
    while(q--){
        cin >> x >> y, x--, y--;
        bool ok = false;
        int p = ufind(x);
        if(siz[p] > ite[p])
            ok = true, ite[p]++;
        if(!ok){
            p = ufind(y);
            if(siz[p] > ite[p])
                ok = true, ite[p]++;
        }
        if(ok)
            umerge(x, y), cout << "LADICA" << endl;
        else cout << "SMECE" << endl;
    }
}