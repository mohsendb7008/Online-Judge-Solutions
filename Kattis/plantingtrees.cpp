#include <bits/stdc++.h>
using namespace std;

// Planting Trees

int n;
int t[100003];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t+1, t+n+1, greater<int>());
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, t[i] + i);
    cout << ans + 1 << endl;
}