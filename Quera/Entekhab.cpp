#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int c[2003][2003];

int main(){
    for(int n = 0; n <= 2000; n++)
        for(int k = 0; k <= n; k++){
            if(!k || k == n)
                c[n][k] = 1;
            else
                c[n][k] = (c[n-1][k-1] + c[n-1][k]) % mod;
        }
    int q, n, k;
    cin >> q;
    while(q--)
        cin >> n >> k, cout << c[n][k] << endl;
}