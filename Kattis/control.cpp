#include <bits/stdc++.h>
using namespace std;

// Association for Control Over Minds

const int m = 500001;
int par[m + 3], ran[m + 3], siz[m + 3];

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

map<int, int> cnt;

int main(){
    iota(par, par + m, 0);
    fill_n(siz, m, 1);
    int n, ans = 0;
    cin >> n;
    while(n--){
        cnt.clear();
        int r, x;
        cin >> r;
        while(r--)
            cin >> x, cnt[ufind(x)]++;
        bool ok = true;
        for(pair<int, int> u : cnt)
            if(u.second < siz[u.first]){
                ok = false;
                break;
            }
        if(ok){
            ans++;
            int u = cnt.begin()->first;
            for(pair<int, int> v : cnt)
                umerge(u, v.first);
        }  
    }
    cout << ans << endl;
}