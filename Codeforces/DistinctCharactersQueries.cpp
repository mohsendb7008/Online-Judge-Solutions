#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, seg[4 * maxn];
char a[maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        seg[v] = 1 << (a[tl] - 'a');
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
        seg[v] = seg[2 * v] | seg[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int pos, char val){
    if(tl == tr)
        seg[v] = 1 << (val - 'a');
    else{
        int mid = (tl + tr) / 2;
        if(pos <= mid)
            update(2 * v, tl, mid, pos, val);
        else
            update(2 * v + 1, mid + 1, tr, pos, val);
        seg[v] = seg[2 * v] | seg[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return seg[v];
    int mid = (tl + tr) / 2;
    return query(2 * v, tl, mid, l, min(r, mid)) | query(2 * v + 1, mid + 1, tr, max(mid+1, l), r);
}

int q, t, pos, l, r;
char c;

int main(){
    scanf("%s", a);
    n = strlen(a);
    build(1, 0, n-1);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %c", &pos, &c);
            update(1, 0, n-1, pos-1, c);
        }
        else if(t == 2){
            scanf("%d %d", &l, &r);
            int mask = query(1, 0, n-1, l-1, r-1), ans = 0;
            while(mask){
                if(mask % 2)
                    ans++;
                mask /= 2;
            }
            printf("%d\n", ans);
        }
    }
}