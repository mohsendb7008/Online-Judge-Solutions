#include <bits/stdc++.h>
using namespace std;

// Forests

int n, cc, par[103], ran[103];
set<int> trees[103];

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));
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

int main(){
    int x, y;
    cin >> n >> x;
    while(cin >> x >> y)
        trees[x-1].insert(y-1);
    cc = n;
    iota(par, par + n, 0);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(trees[i] == trees[j])
                umerge(i, j);
    cout << cc << endl;
}