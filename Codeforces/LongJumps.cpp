#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2e5 + 3;

int n, a[maxn];
num dp[maxn];


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--)
            dp[i] = a[i] + dp[min(n, i + a[i])];
        cout << *max_element(dp, dp + n) << endl;
    }
}
