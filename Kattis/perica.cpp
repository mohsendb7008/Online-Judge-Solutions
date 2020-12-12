#include <bits/stdc++.h>
using namespace std;

// Perica

#define num long long int

const int maxn = 1e5 + 3;
const int mod = 1e9 + 7;

int n, k;
num a[maxn], c[maxn][53];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++){
            if(!j || i == j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    sort(a, a + n);
    num ans = 0;
    for(int i = k-1; i < n; i++)
        ans = (ans + (a[i] * c[i][k-1]) % mod) % mod;
    cout << ans << endl;
}