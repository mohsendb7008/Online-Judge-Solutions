#include <bits/stdc++.h>
using namespace std;

// Large Knapsack

const int maxn = 503, maxk = 2e6 + 3;

int k, n, v[maxn], w[maxn], dp[maxk];

int main(){
    cin >> k >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    for(int i = 0; i < n; i++)
        for(int j = k-w[i]; j >= 0; j--)
            dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]);
    cout << *max_element(dp, dp+k+1) << endl;
}