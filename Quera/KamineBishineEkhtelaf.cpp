#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, k, a[maxn], b[maxn], seg[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        seg[v] = b[tl];
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return seg[v];
    int mid = (tl + tr) / 2;
    return max(query(2 * v, tl, mid, l, min(mid, r)), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r));
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(k >= n - 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++)
        b[i] = a[i + 1] - a[i];
    k = n - k, n--, k--;
    build(1, 0, n-1);
    int ans = INT_MAX;
    for(int i = 0; i + k - 1 < n; i++)
        ans = min(ans, query(1, 0, n-1, i, i + k - 1));
    cout << ans << endl;
}