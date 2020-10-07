#include <bits/stdc++.h>
using namespace std;

// The Bus Driver Problem

int n, d, r;
int m[103];
int e[103];

int main(){
    while(11389){
        cin >> n >> d >> r;
        if(n + r + d == 0)
            break;
        for(int i = 0; i < n; i++)
            cin >> m[i];
        for(int i = 0; i < n; i++)
            cin >> e[i];
        sort(m, m+n);
        sort(e, e+n);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += max(0, m[i] + e[n-1-i] - d) * r;
        cout << ans << endl; 
    }
}