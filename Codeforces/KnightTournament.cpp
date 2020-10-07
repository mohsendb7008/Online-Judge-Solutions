#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int n, m, seg[4 * maxn + 3], won[maxn + 3];

void kill(int v, int tl, int tr, int ql, int qr, int w){
    if(ql > qr)
        return;
    if(seg[v] != -1)
        return;
    if(tl == ql && tr == qr)
        seg[v] = w;
    else{
        int tm = (tl + tr) / 2;
        kill(2 * v, tl, tm, ql, min(qr, tm), w);
        kill(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr, w);
    }
}

void winner(int v, int tl, int tr, int w){
    if(tl == tr)
        won[tl] = (seg[v] != -1) ? seg[v] : w;
    else{
        int tm = (tl + tr) / 2;
        winner(2 * v, tl, tm, (seg[v] != -1) ? seg[v] : w);
        winner(2 * v + 1, tm + 1, tr, (seg[v] != -1) ? seg[v] : w);
    }
}

int main(){
    cin >> n >> m;
    fill_n(seg, 4 * n, -1);
    int l, r, x;
    while(m--){
        cin >> l >> r >> x, l--, r--, x--;
        if(x != l)
            kill(1, 0, n - 1, l, x - 1, x);
        if(x != r)
            kill(1, 0, n - 1, x + 1, r, x);
    }
    winner(1, 0, n - 1, -1);
    for(int i = 0; i < n; i++)
        cout << won[i] + 1 << " ";
    cout << endl;
}