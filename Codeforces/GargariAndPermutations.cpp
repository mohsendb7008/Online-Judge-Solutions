#include <bits/stdc++.h>
using namespace std;

int n, k, seq[8][1003], mapping[8][1003], dp[1003];

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            cin >> seq[i][j], seq[i][j]--;
    for(int i = 0; i < n; i++)
        mapping[0][seq[0][i]] = i;
    for(int i = 1; i < k; i++)
        for(int j = 0; j < n; j++)
            seq[i][j] = mapping[0][seq[i][j]];
    for(int i = 1; i < k; i++)
        for(int j = 0; j < n; j++)
            mapping[i][seq[i][j]] = j;
    for(int i = n-1; i >= 0; i--){
        dp[i] = 1;
        for(int j = i+1; j < n; j++){
            bool ok = 1;
            for(int e = 1; e < k; e++)
                if(mapping[e][j] <= mapping[e][i]){
                    ok = 0;
                    break;
                }
            if(ok)
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    cout << *max_element(dp, dp + n) << endl;
}