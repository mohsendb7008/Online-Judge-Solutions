#include <bits/stdc++.h>
using namespace std;

// Canvas Painting

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        long long int x;
        while(n--)
            cin >> x, pq.push(x);
        long long int ans = 0;
        while(pq.size() > 1){
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << endl;
    }
}