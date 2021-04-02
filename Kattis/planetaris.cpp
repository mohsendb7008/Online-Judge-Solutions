#include <bits/stdc++.h>
using namespace std;

// Planetaris

const int maxn = 1e5 + 3;

int n, a, e[maxn];

int main(){
    cin >> n >> a;
    for(int i = 0; i < n; i++)
        cin >> e[i];
    sort(e, e + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(a >= e[i] + 1)
            ans++, a -= e[i] + 1;
    cout << ans << endl;
}