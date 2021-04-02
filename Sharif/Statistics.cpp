#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;

int n, p[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int alter = p[0], ans = 0;
    for(int i = 1; i < n; i++)
        alter = min(alter, p[i]), ans += p[i] - alter;
    cout << ans << endl;
}