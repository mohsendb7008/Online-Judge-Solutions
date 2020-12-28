#include <bits/stdc++.h>
using namespace std;

#define num long long int

num gcd(num a, num b){
    num mi = min(a, b), ma = max(a, b);
    if(!mi)
        return ma;
    return gcd(ma % mi, mi);
}

const int maxn = 2e5 + 3;

int n, m;
num a[maxn], b[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int j = 0; j < m; j++)
        cin >> b[j];
    if(n == 1){
        for(int i = 0; i < m; i++)
            cout << a[0] + b[i] << " ";
        cout << endl;
        return 0;
    }
    sort(a, a + n);
    num g = 0;
    for(int i = n-2; i >= 0; i--)
        g = gcd(g, a[n-1] - a[i]);
    for(int i = 0; i < m; i++)
        cout << gcd(a[n-1] + b[i], g) << " ";
    cout << endl;
}