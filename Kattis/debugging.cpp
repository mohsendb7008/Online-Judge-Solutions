#include <bits/stdc++.h>
using namespace std;

// Debugging

inline int up(int n, int div){
    if(n % div == 0)
        return n / div;
    return n / div + 1; 
}

long long int n, r, p;
map<int, long long int> memo;

long long int dp(int i){
    if(memo.find(i) != memo.end())
        return memo[i];
    long long int ans = LLONG_MAX;
    for(int k = 2; k <= i; k++)
        ans = min(ans, dp(up(i, k)) + (k-1)*p + r);
    return memo[i] = ans;
}

int main(){ 
    cin >> n >> r >> p;
    memo[1] = 0;
    cout << dp(n) << endl;
}