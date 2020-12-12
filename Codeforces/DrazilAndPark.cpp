#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

#define num long long int

int n, m, a, b;
num d[maxn], h[maxn], toright[maxn], toleft[maxn];
num segr[4 * maxn], indr[4 * maxn], segl[4 * maxn], indl[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr){
        segr[v] = toright[tl], indr[v] = tl;
        segl[v] = toleft[tl], indl[v] = tl;
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * v, tl, mid);
    build(2 * v + 1, mid + 1, tr);
    segr[v] = segr[2 * v], indr[v] = indr[2 * v];
    if(segr[2 * v + 1] > segr[v])
        segr[v] = segr[2 * v + 1], indr[v] = indr[2 * v + 1];
    segl[v] = segl[2 * v], indl[v] = indl[2 * v];
    if(segl[2 * v + 1] > segl[v])
        segl[v] = segl[2 * v + 1], indl[v] = indl[2 * v + 1];
}

pair<num, int> nil = {-1, -1};

pair<num, int> queryl(int v, int tl, int tr, int l, int r){
    if(l > r)
        return nil;
    if(l == tl && r == tr)
        return {segl[v], indl[v]};
    int mid = (tl + tr) / 2;
    pair<num, int> q1 = queryl(2 * v, tl, mid, l, min(r, mid));
    pair<num, int> q2 = queryl(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    if(q1 == nil)
        return q2;
    if(q2 == nil)
        return q1;
    if(q1.first > q2.first)
        return q1;
    return q2;
}

pair<num, int> queryr(int v, int tl, int tr, int l, int r){
    if(l > r)
        return nil;
    if(l == tl && r == tr)
        return {segr[v], indr[v]};
    int mid = (tl + tr) / 2;
    pair<num, int> q1 = queryr(2 * v, tl, mid, l, min(r, mid));
    pair<num, int> q2 = queryr(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    if(q1 == nil)
        return q2;
    if(q2 == nil)
        return q1;
    if(q1.first > q2.first)
        return q1;
    return q2;
}

num seg[4 * maxn];

void buildf(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = 0;
        return;
    }
    int mid = (tl + tr) / 2;
    buildf(2 * v, tl, mid);
    buildf(2 * v + 1, mid + 1, tr);
    seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    pair<num, int> ql = queryl(1, 0, 2 * n - 1, tl, mid);
    pair<num, int> qr = queryr(1, 0, 2 * n - 1, mid + 1, tr);
    num curr = toright[qr.second] - toright[ql.second] + 4 * h[ql.second];
    seg[v] = max(seg[v], curr);
}

pair<num, pair<int, int>> nilf = {-1, {-1, -1}};

pair<num, pair<int, int>> queryf(int v, int tl, int tr, int l, int r){
    if(l > r)
        return nilf;
    if(l == tl && r == tr)
        return {seg[v], {indl[v], indr[v]}};
    int mid = (tl + tr) / 2;
    pair<num, pair<int, int>> ql = queryf(2 * v, tl, mid, l, min(r, mid));
    pair<num, pair<int, int>> qr = queryf(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    if(ql == nilf)
        return qr;
    if(qr == nilf)
        return ql;
    num ans = max(ql.first, qr.first);
    num curr = toright[qr.second.second] - toright[ql.second.first] + 4 * h[ql.second.first];
    return {max(ans, curr), {queryl(v, tl, tr, l, r).second, queryr(v, tl, tr, l, r).second}};
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", d+i);
    for(int i = 0; i < n; i++)
        scanf("%lld", h+i);
    for(int i = 1; i < n; i++)
        d[i + n] = d[i];
    for(int i = 0; i < n; i++)
        h[i + n] = h[i];
    for(int i = 1; i < 2 * n; i++)
        toright[i] = toright[i-1] + d[i];
    for(int i = 0; i < 2 * n; i++)
        toright[i] += 2 * h[i];
    for(int i = 2 * n - 2; i >= 0; i--)
        toleft[i] = toleft[i+1] + d[i+1];
    for(int i = 2 * n - 1; i >= 0; i--)
        toleft[i] += 2 * h[i];
    build(1, 0, 2 * n - 1);
    buildf(1, 0, 2 * n - 1);
    while(m--){
        scanf("%d %d", &a, &b), a--, b--;
        if(a <= b)
            printf("%lld\n", queryf(1, 0, 2 * n - 1, b + 1, a + n - 1));
        else
            printf("%lld\n", queryf(1, 0, 2 * n - 1, b + 1, a - 1));
    }
}