#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;

int n, l, road[maxn], dp[maxn + 1];

int main(){
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> road[i];
    sort(road, road + n);
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        int j = lower_bound(road, road + n, road[i] + l) - road;
        dp[i] = min(1 + dp[i + 1], (j - i - 1) + dp[j]);
    }
    cout << dp[0] << endl;
}