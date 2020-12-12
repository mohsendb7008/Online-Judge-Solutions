#include <bits/stdc++.h>
using namespace std;

// Prime Sieve

const int maxn = 1e8;

bitset<maxn + 1> primeFlags;
int cnt = 0;

int n, q, x;

int main(){
    scanf("%d %d", &n, &q);
    primeFlags.set();
    primeFlags[1] = 0;
    for(int p = 2; p <= n; p++)
        if(primeFlags[p]){
            cnt++;
            for(long long int q = ((long long int)p) * p; q <= n; q += p)
                if(primeFlags[q])
                    primeFlags[q] = 0;
        }
    printf("%d\n", cnt);
    while(q--)
        scanf("%d", &x), printf("%d\n", primeFlags.test(x));
}

