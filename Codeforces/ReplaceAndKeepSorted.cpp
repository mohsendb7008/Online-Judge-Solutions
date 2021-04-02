#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

#define num long long int

int n, q;
num k, a[maxn], b[maxn], ps[maxn];

int main(){
    cin >> n >> q >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == 1){
        int l, r;
        while(q--)
            cin >> l >> r, cout << k-1 << endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++)
        b[i] = a[i+1] - a[i] - 1;
    partial_sum(b, b+n-1, ps);
    int l, r;
    while(q--){
        cin >> l >> r;
        if(l == r)
            cout << k-1 << endl;
        else{
            l--, r--;
            cout << 2 * (ps[r-1] - (l ? ps[l-1] : 0)) + a[l] - 1 + k - a[r] << endl;
        }
    }
}