#include <bits/stdc++.h>
using namespace std;

// Tower Construction

const int maxn = 1e5 + 3;

int n, x[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    int ans = 1;
    for(int i = 0; i < n-1; i++)
        if(x[i+1] > x[i])
            ans++;
    cout << ans << endl;
}