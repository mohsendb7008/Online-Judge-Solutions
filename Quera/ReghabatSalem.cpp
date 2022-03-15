#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

const int maxn = 1e5 + 3;

int n;
long long int p10[maxn], P[maxn];
string s;

int main(){
  cin >> s;
  n = s.size();
  p10[0] = 1;
  for(int i = 1; i <= n; i++){
    p10[i] = (p10[i-1] * 10) % mod;
  }
  P[0] = 0;
  for(int i = 1; i <= n; i++){
    P[i] = (P[i-1] + (i * p10[i-1]) % mod) % mod;
  }
  long long int ans = 0;
  for(int i = 0; i < n; i++){
    int k = (n-1-i);
    long long int u = (1ll * i * (i + 1) / 2) % mod;
    u = (u * p10[k]) % mod;
    long long int v = (P[k] + u) % mod;
    int a = s[i] - '0';
    ans = (ans + (v * a) % mod) % mod;
  }
  cout << ans << endl;
}
