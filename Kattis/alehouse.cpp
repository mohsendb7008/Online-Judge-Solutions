#include <bits/stdc++.h>
using namespace std;

// Alehouse

int n, k;
pair<int, int> a[100003];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        pq.push(a[i].second);
        while(pq.top() < a[i].first - k)
            pq.pop();
        ans = max(ans, (int)pq.size());
    }
    cout << ans << endl;
}