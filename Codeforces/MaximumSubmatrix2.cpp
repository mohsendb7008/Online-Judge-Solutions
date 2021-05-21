#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[5003], nex[5003][5003];
char g[5003][5003];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", g[i]);
    for(int i = 0; i < n; i++)
        for(int j = m-1; j >= 0; j--)
            if(g[i][j] == '1'){
                if(j < m-1 && g[i][j+1] == '1')
                    nex[i][j] = nex[i][j+1];
                else
                    nex[i][j] = j;
            }
    int ans = 0;
    for(int l = 0; l < m; l++){
        fill_n(cnt + 1, m, 0);
        for(int i = 0; i < n; i++)
            if(g[i][l] == '1')
                cnt[nex[i][l] - l + 1]++;
        int sum = 0;
        for(int i = m; i >= 1; i--){
            sum += cnt[i];
            ans = max(ans, sum * i);
        }
    }
    printf("%d\n", ans);
}