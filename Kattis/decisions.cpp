#include <bits/stdc++.h>
using namespace std;

// Decisions, Decisions

int n, m, x, cp, it, heap_sum[(1 << 19) + 3], heap_size[(1 << 19) + 3];

void rec(int u){
    if(u >= 1 << n)
        return;
    rec(2 * u);
    rec(2 * u + 1);
    heap_sum[u] = heap_sum[2 * u] + heap_sum[2 * u + 1];
    heap_size[u] = heap_size[2 * u] + heap_size[2 * u + 1];
}

int ans = 0;

void pre_order(int u){
    ans++;
    if(u >= (1 << n) || heap_sum[u] == 0 || heap_sum[u] == heap_size[u])
        return;
    pre_order(2 * u);
    pre_order(2 * u + 1);
}

int main(){
    cin >> n, m = 1 << n;
    for(int i = 0; i < m; i++){
        cin >> x;
        cp = i;
        it = 1;
        for(int j = 0; j < n; j++){
            it *= 2;
            if(cp % 2)
                it += 1;
            cp /= 2;
        }
        heap_sum[it] = x, heap_size[it] = 1;
    }
    rec(1);
    pre_order(1);
    cout << ans << endl;
}