#include <bits/stdc++.h>
using namespace std;

// Best Coalitions

int n, x, a, b;
int percentage[103];

int dp[103][10003];

bool can(int i, int w){
    if(i == -1)
        return w == 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    bool ans = can(i-1, w);
    if(i != x && w >= percentage[i])
        ans = ans || can(i-1, w-percentage[i]);
    return dp[i][w] = ans;
}

int main(){
    while(11658){
        cin >> n >> x;
        if(n + x == 0)
            break;
        x--;
        for(int i = 0; i < n; i++){
            scanf("%d.%d", &a, &b);
            percentage[i] = a * 100 + b;
        }
        if(percentage[x] > 5000){
            printf("100.00\n");
            continue;
        }
        for(int i = 0; i < n; i++)
            for(int w = 0; w <= 10000; w++)
                dp[i][w] = -1;
        for(int c = 5001 - percentage[x]; 11658; c++)
            if(can(n-1, c)){
                printf("%.2lf\n", (double(percentage[x])/(c + percentage[x]))*100.0);
                break;
            }
    }
}