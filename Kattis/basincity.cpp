#include <bits/stdc++.h>
using namespace std;

// Basin City Surveillance

const int maxn = 1e5 + 3;
int k, n, deg[maxn];
set<int> nadj[maxn];
set<int> R, P;
int pro = 0, mis;
bool ans = 0;

void bron(){
    mis = max(mis, (int)R.size());
    if(ans || pro + R.size() >= k){
        ans = 1;
        return;
    }
    if(P.empty())
        return;
    int u, degm = -1;
    for(int cand : P)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    set<int> PP;
    set_intersection(P.begin(), P.end(), nadj[u].begin(), nadj[u].end(), inserter(PP, PP.begin()));
    for(int v : PP){
        set<int> cR = R, cP = P;
        R.insert(v);
        for(int nv : nadj[v])
            P.erase(nv);
        bron();
        if(ans)
            return;
        R = cR, P = cP;
        P.erase(v);
    }
}

bool vis[maxn];

void dfs(int u){
    vis[u] = 1;
    P.insert(u);
    for(int v : nadj[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; i++){
        int x, j;
        scanf("%d", &x);
        deg[i] = n-1-x;
        nadj[i].insert(i);
        while(x--)
            scanf("%d", &j), nadj[i].insert(j-1);
    }
    if(n >= 5 * k){
        printf("possible");
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            R.clear(), P.clear();
            mis = 0;
            dfs(i);
            bron();
            if(ans){
                printf("possible");
                return 0;
            }
            pro += mis;
        }
    printf("impossible");
}