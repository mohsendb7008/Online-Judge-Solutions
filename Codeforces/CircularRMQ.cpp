#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define inf LLONG_MAX

const int maxn = 2e5 + 3;
int a[maxn], n, q;
num t[4 * maxn];
int l, r, add;
num lazy[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        t[v]  = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

void push(int v){
    t[2 * v] += lazy[v];
    lazy[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, num add){
    if(l > r)
        return;
    if(l == tl && r == tr)
        t[v] += add, lazy[v] += add;
    else{
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), add);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

num query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return inf;
    if(l == tl && r == tr)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    cin.ignore();
    string s;
    while(q--){
        getline(cin, s);
        if(sscanf(s.c_str(), "%d %d %d", &l, &r, &add) == 3){
            if(l <= r)
                update(1, 0, n - 1, l, r, add);
            else
                update(1, 0, n - 1, l, n - 1, add), update(1, 0, n - 1, 0, r, add);
        }
        else{
            if(l <= r)
                cout << query(1, 0, n - 1, l, r) << endl;
            else
                cout << min(query(1, 0, n - 1, l, n - 1), query(1, 0, n - 1, 0, r)) << endl;
        }
    }
}