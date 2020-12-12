#include <bits/stdc++.h>
using namespace std;

// Musical Trees

int n, m, p[103], t[103], cnt[103];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < m; i++)
        cin >> t[i];
    sort(p, p + n);
    sort(t, t + m);
    for(int i = 0; i < n; i++){
        int cl = INT_MAX, cli;
        for(int j = 0; j < m; j++)
            if(abs(p[i] - t[j]) < cl)
                cl = abs(p[i] - t[j]), cli = j;
        cnt[cli]++;
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
        ans += max(cnt[i] - 1, 0);
    cout << ans << endl;
}