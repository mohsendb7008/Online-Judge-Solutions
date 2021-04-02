#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

#define num long long int

set<int> X, H;
int xcnt = 0, hcnt = 0, x[2 * maxn], h[maxn];

int n;

struct building{
    int he, l, r;

    building() = default;

    void fix(){
        he = lower_bound(h, h + hcnt, he) - h;
        r = lower_bound(x, x + xcnt, l + r) - x - 1;
        l = lower_bound(x, x + xcnt, l) - x;
    }

} a[maxn];

map<int, vector<building>> buildings;

int bcnt, b[2 * maxn], ps[2 * maxn], seg[8 * maxn], mark[8 * maxn];

void update(int v, int tl, int tr, int l, int r){
    if(l > r || mark[v])
        return;
    if(tl == l && tr == r){
        mark[v] = 1;
        seg[v] = ps[tr] - (tl ? ps[tl - 1] : 0);
        return;
    }
    int mid = (tl + tr) / 2;
    update(2 * v, tl, mid, l, min(r, mid));
    update(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(mark[v] || (tl == l && tr == r))
        return seg[v];
    int mid = (tl + tr) / 2;
    return query(2 * v, tl, mid, l, min(r, mid)) + query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r >> a[i].he, X.insert(a[i].l), X.insert(a[i].l + a[i].r), H.insert(a[i].he);
    H.insert(0);
    for(int it : X)
        x[xcnt++] = it;
    for(int it : H)
        h[hcnt++] = it;
    for(int i = 0; i < n; i++)
        a[i].fix(), buildings[-a[i].he].push_back(a[i]);
    bcnt = xcnt - 1;
    for(int i = 0; i < bcnt; i++)
        b[i] = x[i + 1] - x[i];
    partial_sum(b, b + bcnt, ps);
    num ans = 0;
    for(auto p : buildings){
        for(auto q : p.second)
            update(1, 0, bcnt - 1, q.l, q.r);
        num hd = h[-p.first] - h[-p.first - 1];
        ans += hd * query(1, 0, bcnt - 1, 0, bcnt - 1);
    }
    cout << ans << endl;
}