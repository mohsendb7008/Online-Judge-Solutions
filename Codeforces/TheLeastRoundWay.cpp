#include <bits/stdc++.h>
using namespace std;

int n, a[1003][1003], dp2[1003][1003], dp5[1003][1003], zx = -1;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(int i = n-1; i >= 0; i--)
        for(int j = n-1; j >= 0; j--){
            if(!a[i][j]){
                zx = i, dp2[i][j] = dp5[i][j] = 1;
                continue;
            }
            int f2 = 0, f5 = 0, cp = a[i][j];
            while(!(cp % 2))
                f2++, cp /= 2;
            cp = a[i][j];
            while(!(cp % 5))
                f5++, cp /= 5;
            if(i == n-1 && j == n-1)
                dp2[i][j] = f2, dp5[i][j] = f5;
            else if(i == n-1)
                dp2[i][j] = dp2[i][j+1] + f2, dp5[i][j] = dp5[i][j+1] + f5;
            else if(j == n-1)
                dp2[i][j] = dp2[i+1][j] + f2, dp5[i][j] = dp5[i+1][j] + f5;
            else{
                dp2[i][j] = min(dp2[i+1][j], dp2[i][j+1]) + f2;
                dp5[i][j] = min(dp5[i+1][j], dp5[i][j+1]) + f5;
            }
        }
    int ans = min(dp2[0][0], dp5[0][0]);
    if(ans && zx != -1){
        printf("1\n");
        for(int i = 0; i < zx; i++)
            printf("D");
        for(int i = 0; i < n-1; i++)
            printf("R");
        for(int i = 0; i < n-1-zx; i++)
            printf("D");
        return 0;
    }
    printf("%d\n", ans);
    if(dp2[0][0] < dp5[0][0]){
        int i = 0, j = 0;
        while(i != n-1 || j != n-1){
            if(i == n-1)
                printf("R"), j++;
            else if(j == n-1)
                printf("D"), i++;
            else if(dp2[i+1][j] < dp2[i][j+1])
                printf("D"), i++;
            else
                printf("R"), j++;
        }
    }else{
        int i = 0, j = 0;
        while(i != n-1 || j != n-1){
            if(i == n-1)
                printf("R"), j++;
            else if(j == n-1)
                printf("D"), i++;
            else if(dp5[i+1][j] < dp5[i][j+1])
                printf("D"), i++;
            else
                printf("R"), j++;
        }
    }
}