#include <bits/stdc++.h>
using namespace std;

// Fair Division

const int maxn = 103;

int t, p, n, b[maxn], ans[maxn];
pair<int, int> a[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> p >> n;
        int sum = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i].first, a[i].second = -i, sum += a[i].first;
        if(sum < p){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            b[i] = p / n;
        int ptr = 0;
        for(int i = 0; i < p % n; i++)
            b[n-1-ptr] += 1, ptr = (ptr + 1) % n;
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            int pay = min(a[i].first, b[i]);
            ans[-a[i].second] = pay;
            if(i == n-1)
                break;
            int rem = b[i] - pay;
            for(int j = i + 1; j < n; j++)
                b[j] += rem / (n - (i + 1));
            ptr %= (n - (i + 1));
            for(int j = 0; j < rem % (n - (i + 1)); j++)
                b[n-1-ptr] += 1,  ptr = (ptr + 1) % (n - (i + 1));
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}