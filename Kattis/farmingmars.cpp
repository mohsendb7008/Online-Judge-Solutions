#include <bits/stdc++.h>
using namespace std;

// Farming Mars

const int maxn = 1e4 + 3;

int n, m, x, y, ph[maxn], bitseg[4 * maxn][24 + 3];
map<int, int> cntseg[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr){
        for(int i = 0; i < 24; i++)
            if(ph[tl] & (1 << i))
                bitseg[v][i] = 1;
        cntseg[v][ph[tl]] = 1;
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * v, tl, mid);
    build(2 * v + 1, mid+1, tr);
    for(int i = 0; i < 24; i++)
        bitseg[v][i] = bitseg[2 * v][i] + bitseg[2 * v + 1][i];
    for(pair<int, int> p : cntseg[2 * v])
        cntseg[v][p.first] += p.second;
    for(pair<int, int> p : cntseg[2 * v + 1])
        cntseg[v][p.first] += p.second; 
}

void query_bits(int v, int tl, int tr, int l, int r, vector<int>& ans){
    if(l > r)
        return;
    if(tl == l && tr == r){
        for(int i = 0; i < 24; i++)
            ans[i] += bitseg[v][i];
        return;
    }
    int mid = (tl + tr) / 2;
    query_bits(2 * v, tl, mid, l, min(r, mid), ans);
    query_bits(2 * v + 1,  mid+1, tr, max(l, mid+1), r, ans);
}

int query_cnt(int v, int tl, int tr, int l, int r, int val){
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return cntseg[v][val];
    int mid = (tl + tr) / 2;
    return query_cnt(2 * v, tl, mid, l, min(r, mid), val) + query_cnt(2 * v + 1, mid+1, tr, max(l, mid+1), r, val);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d.%d", &x, &y), ph[i] = x * 1000000 + y;
    build(1, 0, n-1);
    while(m--){
        scanf("%d %d", &x, &y), x--, y--;
        int maj = (y - x + 1) / 2, ans = 0;
        vector<int> ans_bits(24);
        query_bits(1, 0, n-1, x, y, ans_bits);
        for(int i = 0; i < 24; i++)
            if(ans_bits[i] > maj)
                ans += 1 << i;
        if(query_cnt(1, 0, n-1, x, y, ans) > maj)
            printf("usable\n");
        else
            printf("unusable\n");
    }
}