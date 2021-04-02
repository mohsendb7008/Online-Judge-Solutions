#include <bits/stdc++.h>
using namespace std;

// 0-1 Sequences

const int maxn = 5e5 + 3;

const long mod = 1e9 + 7;

string s;
int n, z[maxn], k[maxn], kp[maxn];
long p2[maxn];

int main(){
    cin >> s;
    n = s.size();
    z[n-1] = (s[n-1] == '0');
    for(int i = n-2; i >= 0; i--)
        z[i] = z[i+1] + (s[i] == '0');
    k[n-1] = (s[n-1] == '?');
    for(int i = n-2; i >= 0; i--)
        k[i] = k[i+1] + (s[i] == '?');
    kp[0] = (s[0] == '?');
    for(int i = 1; i < n; i++)
        kp[i] = kp[i-1] + (s[i] == '?');
    p2[0] = 1;
    for(int i = 1; i <= n; i++)
        p2[i] = (p2[i-1] * 2) % mod;
    long ans = 0;
    for(int i = 0; i < n; i++)
        if(s[i] != '0'){
            long a = (z[i] * p2[k[i] - (s[i] == '?')]) % mod;
            long b = ((k[i] - (s[i] == '?')) * p2[max(0, k[i] - (s[i] == '?') - 1)]) % mod;
            long c = (p2[max(0, kp[i] - (s[i] == '?'))] * (a + b) % mod) % mod;
            ans = (ans + c) % mod;
        }
    cout << ans << endl;
}