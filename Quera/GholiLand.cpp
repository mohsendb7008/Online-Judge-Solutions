#include <bits/stdc++.h>
using namespace std;

int n, q, c[100003], x;

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);
    while(q--)
        cin >> x, cout << lower_bound(c, c + n, x) - c << endl;
}