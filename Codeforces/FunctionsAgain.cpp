#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 + 3;

int n;
num a[maxn], b[maxn], dp[maxn];

inline num max_sub_array(){
    dp[0] = b[0];
    for(int i = 1; i < n-1; i++)
        dp[i] = max(b[i], dp[i-1] + b[i]);
    return *max_element(dp, dp+n-1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n-1; i++)
        b[i] = abs(a[i+1] - a[i]) * ((i % 2) ? -1 : 1);
    num ans = max_sub_array();
    for(int i = 0; i < n-1; i++)
        b[i] *= -1;
    ans = max(ans, max_sub_array());
    cout << ans << endl;
}