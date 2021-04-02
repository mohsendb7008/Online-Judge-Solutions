#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n;
int deg[maxn];

int main(){
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; i++)
        cin >> u >> v, deg[u - 1]++, deg[v - 1]++;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, deg[i]);
    cout << ans << endl;
}