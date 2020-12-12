#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n;
pair<int, int> a[maxn];

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> a[i].first, a[i].second = -(i + 1);
    sort(a, a + n);
    reverse(a, a + n);
    cout << -a[0].second << " " << a[1].first << endl;
}