#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, q, a[maxn], b[maxn];
set<int> cand;

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i), cand.insert(i);
    int t, x, p;
    while(q--){
        scanf("%d %d", &t, &x), x--;
        if(t == 1){
            scanf("%d", &p);
            int k = x;
            while(p){
                auto it = cand.lower_bound(k);
                if(it == cand.end())
                    break;
                k = *it;
                int d = min(p, a[k] - b[k]);
                p -= d, b[k] += d;
                if(a[k] == b[k])
                    cand.erase(k);
                k++;
            }
        }
        else if(t == 2)
            printf("%d\n", b[x]);
    }
}