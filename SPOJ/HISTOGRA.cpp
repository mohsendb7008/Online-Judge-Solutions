#include <bits/stdc++.h>
using namespace std;

// Largest Rectangle in a Histogram

const int maxn = 1e5 + 3;

int n, h[maxn], l[maxn], r[maxn];
priority_queue<pair<int, int>> pq;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> h[i], l[i] = 0, r[i] = n-1;
        for(int i = n-1; i >= 0; i--){
            while(!pq.empty() && pq.top().first > h[i])
                l[pq.top().second] = i+1, pq.pop();
            pq.push({h[i], i});
        }
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().first > h[i])
                r[pq.top().second] = i-1, pq.pop();
            pq.push({h[i], i});
        }
        while(!pq.empty())
            pq.pop();
        long long int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, ((long long int)h[i]) * (r[i]-l[i]+1));
        cout << ans << endl;
    }
}