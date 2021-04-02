#include <bits/stdc++.h>
using namespace std;

int dp[2000], a[10000];

int main(){
    for(int i = 1; i < 2000; i++){
        dp[i] = 1 + dp[i-1];
        if(i >= 2)
            dp[i] = min(dp[i], 1 + dp[i-2]);
        if(i >= 5)
            dp[i] = min(dp[i], 1 + dp[i-5]);
    }
    int t, n;
    scanf("%d", &t);
    while(t--){
        int base = INT_MAX, ans = INT_MAX;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", a + i), a[i] += 1000, base = min(base, a[i]);
        for(int b = 0; b <= base; b++){
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum += dp[a[i] - b];
            ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }
}