// Popularity Contest

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, m, d[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        d[a-1]++, d[b-1]++;
    }
    for(int i = 0; i < n; i++)
        cout << d[i] - (i + 1) << " ";
    cout << endl;
}