#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d %d", &x, &y);
        long long int ans = 0;
        for(int k = 1; 1; k++){
            int bound = min(y+1, x/k);
            if(bound < k+2)
                break;
            ans += bound-(k+2)+1;
        }
        printf("%lld\n", ans);
    }    
}