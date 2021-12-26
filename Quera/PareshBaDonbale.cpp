#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int n, a[maxn + 3], b[maxn + 3], dp[maxn + 3], apbV[maxn + 3], apbM[maxn + 3], ambV[maxn + 3], ambM[maxn + 3], segAPB[4 * maxn + 3], segAMB[4 * maxn + 3];
pair<int, int> p[maxn + 3], apb[maxn + 3], amb[maxn + 3];

void update(int* seg, int v, int tl, int tr, int pos, int value){
    if(tl == tr)
        seg[v] = value;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(seg, 2 * v, tl, tm, pos, value);
        else
            update(seg, 2 * v + 1, tm + 1, tr, pos, value);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    }
}

int query(int* seg, int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return seg[v];
    int tm = (tl + tr) / 2;
    return max(query(seg, 2 * v, tl, tm, l, min(tm, r)), query(seg, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].first;
    for(int i = 0; i < n; i++)
        cin >> p[i].second;
    sort(p, p + n);
    for(int i = 0; i < n; i++)
        a[i] = p[i].first, b[i] = p[i].second;
    for(int i = 0; i < n; i++)
        apb[i] = {a[i] + b[i], i}, amb[i] = {a[i] - b[i], i};
    sort(apb, apb + n);
    sort(amb, amb + n);
    for(int i = 0; i < n; i++)
        apbV[i] = apb[i].first, ambV[i] = amb[i].first;
    for(int i = 0; i < n; i++)
        apbM[apb[i].second] = i, ambM[amb[i].second] = i;
    for(int i = n-1; i >= 0; i--){
        int ans = 0;
        int l1 = upper_bound(apbV, apbV + n, a[i] + b[i]) - apbV;
        if(l1 > 0)
            ans = max(ans, query(segAPB, 1, 0, n-1, 0, l1 - 1));
        int l2 = upper_bound(ambV, ambV + n, a[i] - b[i]) - ambV;
        if(l2 > 0)
            ans = max(ans, query(segAMB, 1, 0, n-1, 0, l2 - 1));
        dp[i] = 1 + ans;
        update(segAPB, 1, 0, n-1, apbM[i], dp[i]);
        update(segAMB, 1, 0, n-1, ambM[i], dp[i]);
    }
    cout << *max_element(dp, dp + n) << endl;
}