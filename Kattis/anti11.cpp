#include <bits/stdc++.h>
using namespace std;

// Ocean's Anti-11

const int maxn = 1e5 + 3;
const int mod = 1e9 + 7;

int fib[maxn];

int main(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < maxn; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    int t, n;
    cin >> t;
    while(t--)
        cin >> n, cout << fib[n+1] << endl;
}