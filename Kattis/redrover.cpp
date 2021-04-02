#include <bits/stdc++.h>
using namespace std;

// Red Rover

int n, ans = INT_MAX, lcp[103];
char s[103];

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int x = 0; x < n; x++)
        for(int y = x; y < n; y++){
            lcp[x] = 0;
            int i = x + 1, j = x;
            while(i <= y){
                if(s[i] == s[j])
                    lcp[i] = j - x + 1, i++, j++;
                else if(j > x)
                    j = x + lcp[j - 1];
                else
                    lcp[i] = 0, i++;
            }
            i = 0, j = x;
            int cnt = 0;
            while(i < n){
                if(s[i] == s[j]){
                    i++, j++;
                    if(j == y + 1){
                        cnt++;
                        j = x;
                    }
                }
                else if(j > x)
                    j = x + lcp[j - 1];
                else
                    i++;
            }
            ans = min(ans, n - ((cnt - 1) * (y - x + 1)) + cnt);
        }
    printf("%d", min(ans, n));
}