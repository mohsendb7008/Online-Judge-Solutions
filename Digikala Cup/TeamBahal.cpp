#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1000000007;

const int maxn = 1e5 + 3;

int n, k;
pair<num, num> a[maxn];
priority_queue<num, vector<num>, greater<num>> window;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].second;
    for(int i = 0; i < n; i++)
        cin >> a[i].first;
    cin >> k;
    sort(a, a + n);
    num sum = 0, ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(window.size() < k){
            sum += a[i].second;
            window.push(a[i].second);
        }
        else if(window.top() < a[i].second){
            sum += a[i].second - window.top();
            window.pop();
            window.push(a[i].second);
        }
        ans = max(ans, a[i].first * sum);
    }
    cout << ans % mod << endl;
}