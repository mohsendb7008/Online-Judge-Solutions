#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, a[maxn], b[maxn], mapping[maxn];
multiset<int> distances;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        mapping[a[i]] = i + 1;
    for(int i = 0; i < n; i++)
        b[i] = mapping[b[i]];
    for(int i = 0; i < n; i++)
        distances.insert(b[i] - (i + 1));
    for(int i = 0; i < n; i++){
        auto it = distances.upper_bound(-i);
        int ans = INT_MAX;
        if(it != distances.end())
            ans = min(ans, abs(*it + i));
        if(it != distances.begin())
            ans = min(ans, abs(*prev(it) + i));
        cout << ans << endl;
        distances.erase(distances.find(b[i] - 1 - i));
        distances.insert(b[i] - n - (i + 1));
    }
}