#include <bits/stdc++.h>
using namespace std;

int l = 6 * 60 + 30, r = 19 * 60;
int n, x, y;

int main(){
    int mi = INT_MAX, ma = INT_MIN;
    scanf("%d", &n);
    while(n--){
        scanf("%d:%d", &x, &y), x = 60 * x + y;
        if(x >= l && x <= r)
            mi = min(mi, x), ma = max(ma, x);
    }
    if(mi == INT_MAX){
        printf("0\n");
        return 0;
    }
    if(mi >= 6 * 60 + 30 && mi <= 10 * 60 && ma >= 6 * 60 + 30 && ma <= 16 * 60)
        printf("24000\n");
    else if(mi >= 6 * 60 + 30 && mi <= 10 * 60 && ma >= 16 * 60 + 1 && ma <= 19 * 60)
        printf("36000\n");
    else if(mi >= 10 * 60 + 1 && mi <= 16 * 60 && ma >= 10 * 60 + 1 && ma <= 16 * 60)
        printf("16800\n");
    else
        printf("24000\n");
}