#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 +3;

int n, q, s, k;
num a[maxn], psum[maxn][322];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    int up = sqrt(n);
    for(int k = 1; k <= up; k++)
        for(int i = n-1; i >= 0; i--)
            psum[i][k] = a[i] + ((i + k) >= n ? 0 : psum[i + k][k]);
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &s, &k), s--;
        if(k <= up)
            printf("%lld\n", psum[s][k]);
        else{
            num ans = 0, it = s;
            while(it < n)
                ans += a[it], it += k;
            printf("%lld\n", ans);
        }
    }
}