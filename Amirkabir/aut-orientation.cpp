#include <bits/stdc++.h>
using namespace std;

const int maxn = 133;

int n, deg[maxn];
set<int> adj[maxn];
set<int> R, P, X;

int ans = 0;
int cnt = 1;

void bron(){
    if(P.empty() && X.empty()){
        int curr = R.size();
        if (curr > ans) {
            ans = R.size();
            cnt = 1;
        }
        else if(curr == ans) {
            cnt++;
        }
        return;
    }
	if(P.empty())
		return;
    int u, degm = -1;
    for(int cand : P)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    for(int cand : X)
        if(deg[cand] > degm)
            u = cand, degm = deg[cand];
    set<int> PP = P;
    for(int nu : adj[u])
        PP.erase(nu);
    for(int v : PP){
        set<int> cR = R, cP = P, cX = X;
        R.insert(v);
        P.clear();
        X.clear();
        for(int nv : adj[v]){
            if(cP.find(nv) != cP.end())
                P.insert(nv);
            if(cX.find(nv) != cX.end())
                X.insert(nv);
        }
        bron();
        R = cR, P = cP, X = cX;
        P.erase(v);
        X.insert(v);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(i != j && !x) {
                adj[i].insert(j);
            }
        }
    }
    for(int i = 0; i < n; i++)
        deg[i] = adj[i].size(), P.insert(i);
    bron();
    cout << ans << " " << cnt << endl;
}