#include <bits/stdc++.h>
using namespace std;

int n, c, x[1000003];

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n, greater<int>());
    for(int i = 0; i < n; i++)
        c -= min(c, max(0, x[i] - c));
    cout << c << endl;
}