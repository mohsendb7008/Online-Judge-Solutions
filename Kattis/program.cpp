#include <bits/stdc++.h>
using namespace std;

// Program

#define num long long int

const int maxn = 1e6 + 3;

int n, k, q;
num a[maxn], b[maxn], psum[maxn];

int main(){
    scanf("%d %d", &n, &k);
    int x, y;
    while(k--)
        scanf("%d", &x), b[x]++;
    for(int i = 1; i < n; i++){
        if(!b[i])
            continue;
        for(int j = 0; j < n; j+=i)
            a[j] += b[i];
    }
    partial_sum(a, a + n, psum);
    scanf("%d", &q);
    while(q--)
        scanf("%d %d", &x, &y), printf("%lld\n", (psum[y] - (x ? psum[x-1] : 0)));
}