#include <bits/stdc++.h>
using namespace std;

// Just for Sidekicks

#define num long long int

const int maxn = 2e5;

int n, q, gemv[9], gem[maxn+3], ft[9][maxn+3];

int rsq(int f, int i){
    int sum = 0;
    while(i)
        sum += ft[f][i], i -= i & (-i);
    return sum;
}

void inc(int f, int i, int k){
    while(i <= n)
        ft[f][i] += k, i += i & (-i);
}

int main(){
    scanf("%d %d\n", &n, &q);
    for(int i = 1; i <= 6; i++)
        scanf("%d", gemv+i);
    scanf("\n");
    char c;
    for(int i = 1; i <= n; i++)
        scanf("%c", &c), gem[i] = c - '0';
    scanf("\n");
    for(int i = 1; i <= n; i++)
        inc(gem[i], i, 1);
    int t, x, y;
    while(q--){
        scanf("%d %d %d\n", &t, &x, &y);
        if(t == 1){
            inc(gem[x], x, -1);
            gem[x] = y;
            inc(gem[x], x, 1);
        }
        else if(t == 2)
            gemv[x] = y;
        else{
            num ans = 0;
            for(int f = 1; f <= 6; f++)
                ans += ((num)gemv[f]) * (rsq(f, y) - (x > 1 ? rsq(f, x-1) : 0));
            printf("%lld\n", ans);
        }
    }
}