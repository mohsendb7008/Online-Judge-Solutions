#include <bits/stdc++.h>
using namespace std;

// Synchronizing Lists

int n, b[5003], ans[5003];
pair<int, int> a[5003];

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> a[i].first, a[i].second = i;
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a+n);
        sort(b, b+n);
        for(int i = 0; i < n; i++)
            ans[a[i].second] = b[i];
        for(int i = 0; i < n; i++)
            cout << ans[i] << '\n';
        cout << '\n';
    }
}