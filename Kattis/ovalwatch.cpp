#include <bits/stdc++.h>
using namespace std;

// OvalWatch

const int maxn = 5e3 + 3;
const int maxk = 1e5 + 3;

int n, k, a[maxn], ans[maxn];
pair<int, int> legs[maxk];

int main(){
    cin >> n >> k;
    iota(a, a + n, 0);
    for(int i = 0; i < k; i++)
        cin >> legs[i].second >> legs[i].first;
    sort(legs, legs + k);
    for(int i = 0; i < k; i++)
        swap(a[legs[i].second], a[legs[i].second + 1]);
    for(int i = 0; i < n; i++)
        ans[a[i]] = i;
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}