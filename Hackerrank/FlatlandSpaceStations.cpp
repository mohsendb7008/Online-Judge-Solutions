#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int inf = INT_MAX;

int n, m, stations[maxn], nearest[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> stations[i];
    fill_n(nearest, n, inf);
    sort(stations, stations+m);
    for(int i = 0; i < m; i++)
        for(int j = stations[i]; j < ((i == m-1) ? n : stations[i+1]); j++)
            nearest[j] = min(nearest[j], j - stations[i]);
    for(int i = m-1; i >= 0; i--)
        for(int j = stations[i]; j >= ((i == 0) ? 0 : stations[i-1]+1); j--)
            nearest[j] = min(nearest[j], stations[i] - j);
    cout << *max_element(nearest, nearest + n) << endl;
}