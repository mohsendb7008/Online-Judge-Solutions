#include <bits/stdc++.h>
using namespace std;

// Union-Find

const int maxn = 1e6 + 3;

int n, q;
int par[maxn], ran[maxn];

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));
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
    scanf("%d %d\n", &n, &q);
    iota(par, par + n, 0);
    char c;
    int x, y;
    while(q--){
        scanf("%c %d %d\n", &c, &x, &y);
        if(c == '=')
            umerge(x, y);
        else 
            printf((ufind(x) == ufind(y) ? "yes\n" : "no\n"));
    }
}