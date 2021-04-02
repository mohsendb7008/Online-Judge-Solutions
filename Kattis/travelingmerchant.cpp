#include <bits/stdc++.h>
using namespace std;

// Traveling Merchant

const int maxn = 1e5 + 3;

int n, a[maxn], b[maxn], week[7]{0, 1, 2, 3, 2, 1, 0}, seg[4 * maxn][7 + 3], smax[4 * maxn][7 + 3], smin[4 * maxn][7 + 3];

void build(int v, int tl, int tr, int d){
    if(tl == tr){
        seg[v][d] = 0;
        smax[v][d] = smin[v][d] = a[tl] + week[d] * b[tl];
        return;
    }
    int mid = (tl + tr) / 2, e = (d + mid - tl + 1) % 7;
    build(2 * v, tl, mid, d);
    build(2 * v + 1, mid + 1, tr, e);
    seg[v][d] = max(seg[2 * v][d], max(seg[2 * v + 1][e], smax[2 * v + 1][e] - smin[2 * v][d]));
    smax[v][d] = max(smax[2 * v][d], smax[2 * v + 1][e]);
    smin[v][d] = min(smin[2 * v][d], smin[2 * v + 1][e]);
}

const pair<pair<int, int>, pair<int, int>> nil = {{0, 0}, {-1, -1}};

pair<pair<int, int>, pair<int, int>> query(int v, int tl, int tr, int d, int l, int r){
    if(l > r)
        return nil;
    if(tl == l && tr == r)
        return {{seg[v][d], tr - tl + 1}, {smax[v][d], smin[v][d]}};
    int mid = (tl + tr) / 2;
    pair<pair<int, int>, pair<int, int>> ql = query(2 * v, tl, mid, d, l, min(r, mid));
    pair<pair<int, int>, pair<int, int>> qr = query(2 * v + 1, mid+1, tr, (d + ql.first.second) % 7, max(l, mid+1), r);
    pair<pair<int, int>, pair<int, int>> ans = nil;
    if(ql != nil && qr != nil){
        ans.first.first = max(ql.first.first, max(qr.first.first, qr.second.first - ql.second.second));
        ans.first.second = ql.first.second + qr.first.second;
        ans.second.first = max(ql.second.first, qr.second.first);
        ans.second.second = min(ql.second.second, qr.second.second);
    }
    else if(ql != nil)
        ans = ql;
    else if(qr != nil)
        ans = qr;
    return ans;
}

int q, s[maxn], t[maxn], ans[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cin >> q;
    for(int i = 0; i < q; i++)
        cin >> s[i] >> t[i], s[i]--, t[i]--;
    for(int i = 0; i < 7; i++)
        build(1, 0, n-1, i);
    for(int i = 0; i < q; i++)
        if(s[i] < t[i])
            ans[i] = max(query(1, 0, n-1, 0, s[i], t[i]).first.first, 0);
    reverse(a, a + n);
    reverse(b, b + n);
    for(int i = 0; i < 7; i++)
        build(1, 0, n-1, i);
    for(int i = 0; i < q; i++)
        if(s[i] > t[i])
            ans[i] = max(query(1, 0, n-1, 0, n-1-s[i], n-1-t[i]).first.first, 0);
    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;
}