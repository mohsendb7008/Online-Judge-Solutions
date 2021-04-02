#include <bits/stdc++.h>
using namespace std;

// Association of Cats and Magical Lights

const int maxn = 3e5 + 3;

int n, q, k, x, color[maxn], par[maxn], preorder[maxn], nexty[maxn], place[maxn], cnt = 1;
vector<int> adj[maxn];

void dfs(int u){
    int save = cnt;
    place[u] = cnt;
    preorder[cnt++] = u;
    for(int v : adj[u])
        dfs(v);
    nexty[save] = cnt;
}

class FenwickTree { // Notice: it is 1-based fenwick-tree.
    private: 
    vector<long long int> ft;
    public:
    FenwickTree(){
        ft.assign(maxn, 0); // init n + 1 zeroes
    }
    long long int rsq(long long int b) { // returns RSQ(1, b)
        long long int summ = 0;
        for (; b; b -= (b & (-b)))
            summ += ft[b];
        return summ; 
    }
    long long int rsq(int a, int b) { // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(long long int k, long long int v) { // note: n = ft.size() - 1
        for (; k < ft.size(); k += (k & (-k)))
            ft[k] += v;
    }
} trees[103];


int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", color + i);
    for(int i = 1; i < n; i++)
        scanf("%d", par + i), par[i]--, adj[par[i]].push_back(i);
    dfs(0);
    for(int i = 1; i <= n; i++)
        trees[color[preorder[i]]].adjust(i, 1);
    while(q--){
        scanf("%d %d", &k, &x), x--;
        if(k){
            if(color[x] == k)
                continue;
            trees[color[x]].adjust(place[x], -1);
            trees[k].adjust(place[x], 1);
            color[x] = k;
        }
        else{
            int ans = 0;
            for(int i = 1; i <= 100; i++)
                ans += trees[i].rsq(place[x], nexty[place[x]] - 1) % 2;
            printf("%d\n", ans);
        }
    }
}