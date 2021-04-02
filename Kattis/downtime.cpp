#include <bits/stdc++.h>
using namespace std;

// Disastrous Downtime

int n, k;
int requests[100003];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> requests[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = lower_bound(requests, requests + n, requests[i] + 1000) - requests - i;
        int servers = cnt / k + (cnt % k ? 1 : 0);
        ans = max(ans, servers);
    }
    cout << ans << endl;
}