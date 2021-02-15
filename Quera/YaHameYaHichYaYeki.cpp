#include <bits/stdc++.h>
using namespace std;

int n, s, siz[2003], sum[2003], mi[2003], dp[2003][2003], tr[2003][2003];

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> siz[i], mi[i] = INT_MAX;
        int t = siz[i], x;
        while(t--)
            cin >> x, sum[i] += x, mi[i] = min(mi[i], x);
    }
    for(int i = n-1; i >= 0; i--)
        for(int s = 0; s <= 2000; s++){
            dp[i][s] = dp[i+1][s], tr[i][s] = 0;
            if(siz[i]){
                if(mi[i] <= s && dp[i][s] < dp[i+1][s-mi[i]] + 1)
                    dp[i][s] = dp[i+1][s-mi[i]] + 1, tr[i][s] = 1;
                if(sum[i] <= s && dp[i][s] < dp[i+1][s-sum[i]] + siz[i])
                    dp[i][s] = dp[i+1][s-sum[i]] + siz[i], tr[i][s] = 2;
            }
        }
    cout << dp[0][s] << endl;
    for(int i = 0; i < n; i++){
        cout << tr[i][s];
        if(tr[i][s] == 1)
            s -= mi[i];
        else if(tr[i][s] == 2)
            s -= sum[i];
        
    }
    cout << endl;
}