#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;

int t[4 * maxn + 3];

void update(int v, int tl, int tr, int pos, int value){
    if(tl == tr)
        t[v] = value;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2 * v, tl, tm, pos, value);
        else
            update(2 * v + 1, tm + 1, tr, pos, value);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int lq = query(2 * v, tl, tm, l, min(tm, r));
    int rq =  query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return max(lq, rq);
}

int n, key[maxn], value[maxn];
pair<int, int> a[maxn], xw[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        xw[i] = {a[i].first + a[i].second, i};
    sort(xw, xw + n);
    for(int i = 0; i < n; i++)
        key[xw[i].second] = i;
    for(int i = 0; i < n; i++)
        value[i] = xw[i].first;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int dp = 1;
        int u = upper_bound(value, value + n, a[i].first - a[i].second) - value;
        if(u)
            dp = 1 + query(1, 0, n-1, 0, u-1);
        ans = max(ans, dp);
        update(1, 0, n-1, key[i], dp);
    }
    cout << ans << endl;
}