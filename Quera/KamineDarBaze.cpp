#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int n, q, a[maxn + 3], t[4 * maxn + 3];

void build(int v, int tl, int tr){
    if(tl == tr)
        t[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr)
        t[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return INT_MAX;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n-1, l, r) << endl;
    }
}