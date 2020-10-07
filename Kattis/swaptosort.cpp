#include <bits/stdc++.h>
using namespace std;

// Swap to Sort

const int maxn = 1e6 + 3;

int n, q, par[maxn], ran[maxn];

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n >> q;
    iota(par, par + n, 0);
    int x, y;
    while(q--)
        cin >> x >> y, umerge(x-1, y-1);
    for(int i = 0; i < n / 2; i++)
        if(ufind(i) != ufind(n - 1 - i)){
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
}