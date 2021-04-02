#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 3;

int n, k, a[maxn], nexty[maxn];
vector<int> ind[maxn];
set<int> cache;

int seg[4 * maxn], iseg[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = INT_MIN;
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * v, tl, mid);
    build(2 * v + 1, mid + 1, tr);
}

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        seg[v] = val;
        iseg[v] = pos;
        return;
    }
    int mid = (tl + tr) / 2;
    if(pos <= mid)
        update(2 * v, tl, mid, pos, val);
    else
        update(2 * v + 1, mid + 1, tr, pos, val);
    seg[v] = seg[2 * v];
    iseg[v] = iseg[2 * v];
    if(seg[2 * v + 1] > seg[v])
        seg[v] = seg[2 * v + 1], iseg[v] = iseg[2 * v + 1];
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = n - 1; i >= 0; i--){
        if(ind[a[i]].empty())
            nexty[i] = n;
        else
            nexty[i] = ind[a[i]].back();
        ind[a[i]].push_back(i);
    }
    build(1, 0, n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cache.find(a[i]) == cache.end()){
            ans++;
            if(cache.size() < k)
                cache.insert(a[i]);
            else{
                int rem = iseg[1];
                update(1, 0, n, rem, INT_MIN);
                cache.erase(rem);
                cache.insert(a[i]);
            }
        }
        update(1, 0, n, a[i], nexty[i]);
    }
    cout << ans << endl;
}