#include <bits/stdc++.h>
using namespace std;

int h, n, m, p, b, a[(1 << 17) + 3], seg[4 * (1 << 17) + 3];

void build(int v, int tl, int tr, bool o){
    if(tl == tr)
        seg[v] = a[tl];
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid, !o);
        build(2 * v + 1, mid + 1, tr, !o);
        if(o)
            seg[v] = seg[2 * v] | seg[2 * v + 1];
        else
            seg[v] = seg[2 * v] ^ seg[2 * v + 1];
    }
}

void update(int v, int tl, int tr, bool o, int pos, int val){
    if(tl == tr)
        seg[v] = val;
    else{
        int mid = (tl + tr) / 2;
        if(pos <= mid)
            update(2 * v, tl, mid, !o, pos, val);
        else
            update(2 * v + 1, mid + 1, tr, !o, pos, val);
        if(o)
            seg[v] = seg[2 * v] | seg[2 * v + 1];
        else
            seg[v] = seg[2 * v] ^ seg[2 * v + 1];
    }
}

int main(){
    cin >> h >> m, n = 1 << h;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n-1, h % 2);
    while(m--)
        cin >> p >> b, update(1, 0, n-1, h % 2, p-1, b), cout << seg[1] << endl;
}