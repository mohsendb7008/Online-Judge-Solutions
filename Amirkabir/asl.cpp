#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int N, X, Y;
unordered_map<int, long long int> dp;

inline int mhash(int n, int x, int y, int b, int u){
    // x y n b u
    return x * 101 * 35 * 2 * 2 + y * 35 * 2 * 2 + n * 2 * 2 + b * 2 + u;
}

long long int cdp(int n, int x, int y, int b, int u){
    if(n == N)
        return x == 0 && y == 0;
    int key = mhash(n, x, y, b, u);
    auto it = dp.find(key);
    if(it != dp.end())
        return it->second;
    long long int ans = 0;
    if(!b){
        ans = (ans + cdp(n, x, y, 1, u)) % mod;
        if(x && y){
            ans = (ans + cdp(n, x-1, y-1, 0, 1)) % mod;
        }
    }
    else{
        if(u){
            ans = (ans + cdp(n+1, x, y, 0, 0)) % mod;
        }
        if(x){
            ans = (ans + cdp(n, x-1, y, 1, 1)) % mod;
        }
    }
    return dp[mhash(n, x, y, b, u)] = ans;
}

int main(){
    cin >> N >> X >> Y;
    cout << cdp(0, X, Y, 0, 0) << endl; 
}