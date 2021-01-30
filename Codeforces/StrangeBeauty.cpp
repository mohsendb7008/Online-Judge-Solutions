#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, num[maxn], profit[maxn], dp[maxn];
map<int, int> mp;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = n;
        mp.clear();
        int x;
        while(n--)
            scanf("%d", &x), mp[x]++;
        n++;
        for(auto it : mp)
            num[n] = it.first, profit[n] = it.second, n++;
        mp.clear();
        for(int i = 0; i < n; i++)
            mp[num[i]] = i;
        for(int i = n-1; i >= 0; i--){
            dp[i] = profit[i];
            long long int a = num[i], b = 2;
            while(a * b <= num[n-1]){
                auto it = mp.find(a * b);
                if(it != mp.end())
                    dp[i] = max(dp[i], profit[i] + dp[it->second]);
                b++;
            } 
        }
        ans -= *max_element(dp, dp + n);
        printf("%d\n", ans);
    }
}