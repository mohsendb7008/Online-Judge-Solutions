#include <bits/stdc++.h>
using namespace std;

int h, m, n, a[(1<<17)+3], seg[4*(1<<17)+3];

void build(int v, int tl, int tr, bool op){
    if(tl == tr)
        seg[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, !op);
        build(2 * v + 1, tm + 1, tr, !op);
        if(!op)
            seg[v] = seg[2 * v] ^ seg[2 * v + 1];
        else 
            seg[v] = seg[2 * v] | seg[2 * v + 1]; 
    }
}

void update(int v, int tl, int tr, int ind, int val, bool op){
    if(tl == tr)
        seg[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(ind <= tm)
            update(2 * v, tl, tm, ind, val, !op);
        else
            update(2 * v + 1, tm + 1, tr, ind, val, !op);
        if(!op)
            seg[v] = seg[2 * v] ^ seg[2 * v + 1];
        else
            seg[v] = seg[2 * v] | seg[2 * v + 1];
        
    }
}

int main(){
    cin >> h >> m, n = 1 << h;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n-1, h % 2);
    int p, b;
    while(m--)
        cin >> p >> b, update(1, 0, n-1, p - 1, b, h % 2), cout << seg[1] << endl;
}