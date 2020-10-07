#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree

#define num long long int

int n, q;
num ft[5000003];

num rsq(int i){
    num ans = 0;
    while(i)
        ans += ft[i], i -= (i & (-i));
    return ans;
}

void inc(int i, num k){
    while(i <= n)
        ft[i] += k, i += (i & (-i));
}

int main(){
    char c;
    int i, k;
    scanf("%d %d\n", &n, &q);
    while(q--){
        scanf("%c", &c);
        if(c == '+')
            scanf("%d %d\n", &i, &k), inc(i + 1, k);
        else
            scanf("%d\n", &i), printf("%lld\n", (i ? rsq(i) : 0));       
    }
}