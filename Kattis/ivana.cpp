#include <bits/stdc++.h>
// Ivana

int n;
int cards[103];

int dp[103][103][203][3];

int cdp(int i, int j, int o, bool ivana){
    if(dp[i][j][o+n][ivana] != -1)
        return dp[i][j][o+n][ivana];
    if(i == (j + 1) % n)
        return dp[i][j][o+n][ivana] = o > 0;
    bool subp1 = cdp((i+1)%n, j, ivana ? (o + ((cards[i]%2)==1)) : (o - ((cards[i]%2)==1)), !ivana);
    bool subp2 = cdp(i, (j-1+n)%n, ivana ? (o + ((cards[j])%2==1)) : (o - ((cards[j]%2)==1)), !ivana);
    return dp[i][j][o+n][ivana] = ivana ? (subp1 || subp2) : (subp1 && subp2);
}

int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++)
        std::cin >> cards[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 203; k++)
                for(int t = 0; t < 2; t++)
                    dp[i][j][k][t] = -1;
    int ans = 0;
    for(int cand = 0; cand < n; cand++)
        ans += cdp((cand+1)%n, (cand-1+n)%n, (cards[cand]%2)==1, false);
    std::cout << ans << std::endl;
}