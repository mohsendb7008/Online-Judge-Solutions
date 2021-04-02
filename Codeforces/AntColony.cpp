#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b){
    int mi = min(a, b), ma = max(a, b);
    if(!mi)
        return ma;
    return gcd(ma % mi, mi);
}

const int maxn = 1e5 + 3;
int n, t, l, r, a[maxn], seg[4 * maxn], cnt[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        seg[v] = a[tl], cnt[v] = 1;
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid+1, tr);
        seg[v] = gcd(seg[2 * v], seg[2 * v + 1]);
        if(seg[v] == seg[2 * v] && seg[v] == seg[2 * v + 1])
            cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
        else if(seg[v] == seg[2 * v])
            cnt[v] = cnt[2 * v];
        else if(seg[v] == seg[2 * v + 1])
            cnt[v] = cnt[2 * v + 1];
        else
            cnt[v] = 0;
    }
}

const pair<int, int> nil = {-1, 0};

pair<int, int> query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return nil;
    if(tl == l && tr == r)
        return {seg[v], cnt[v]};
    int mid = (tl + tr) / 2;
    pair<int, int> ql = query(2 * v, tl, mid, l, min(r, mid));
    pair<int, int> qr = query(2 * v + 1, mid+1, tr, max(l, mid+1), r);
    pair<int, int> ans = nil;
    if(ql != nil && qr != nil){
        ans.first = gcd(ql.first, qr.first);
        if(ans.first == ql.first && ans.first == qr.first)
            ans.second = ql.second + qr.second;
        else if(ans.first == ql.first)
            ans.second = ql.second;
        else if(ans.first == qr.first)
            ans.second = qr.second;
        else
            ans.second = 0;
    }
    else if(ql != nil)
        ans = ql;
    else if(qr != nil)
        ans = qr;
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n-1);
    cin >> t;
    while(t--)
        cin >> l >> r, cout << r - l + 1 - query(1, 0, n-1, l-1, r-1).second << endl;
}