#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 3;

int n, m, l, r, x, seg[4 * maxn], heap[maxn];

void build(int v, int tl, int tr){
    seg[v] = -1;
    if(tl == tr)
        heap[tl] = v;
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid + 1, tr);
    }
}

void trace(int v, int tl, int tr, int l, int r, int winner){
    if(l > r || seg[v] != -1)
        return;
    if(tl == l && tr == r){
        seg[v] = winner;
        return;
    }
    int mid = (tl + tr) / 2;
    trace(2 * v, tl, mid, l, min(r, mid), winner);
    trace(2 * v + 1, mid+1, tr, max(l, mid+1), r, winner);
}

int main(){
    cin >> n >> m;
    build(1, 0, n-1);
    while(m--){
        cin >> l >> r >> x, l--, r--, x--;
        trace(1, 0, n-1, l, x-1, x);
        trace(1, 0, n-1, x+1, r, x);
    }
    for(int i = 0; i < n; i++){
        int it = heap[i], ans = -1;
        while(it && ans == -1)
            ans = seg[it], it /= 2;
        cout << ans + 1 << " "; 
    }
    cout << endl;
}