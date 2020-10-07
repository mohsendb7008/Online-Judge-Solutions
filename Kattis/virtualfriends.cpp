#include <bits/stdc++.h>
using namespace std;

// Virtual Friends

const int maxn = 2e5 + 3;

int n;
map<string, int> id;
int par[maxn], ran[maxn], siz[maxn];
inline int gid(string s){
    if(id.find(s) != id.end())
        return id[s];
    id[s] = n, par[n] = n, ran[n] = 0, siz[n] = 1;
    return n++;
}

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
    }
    else{
        par[i] = j;
        siz[j] += siz[i];
        if(ran[i] == ran[j])
            ran[j]++;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        n = 0, id.clear();
        int m;
        cin >> m;
        string x, y;
        while(m--){
            cin >> x >> y;
            int i = gid(x), j = gid(y);
            umerge(i, j);
            cout << siz[ufind(i)] << endl;
        }
    }
}