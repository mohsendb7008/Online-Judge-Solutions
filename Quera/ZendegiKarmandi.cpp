#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
int n, d[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d + n);
    int day = 1, ans = 0;
    for(int i = 0; i < n; i++)
        if(day <= d[i])
            day++, ans++;
    cout << ans << endl;
}