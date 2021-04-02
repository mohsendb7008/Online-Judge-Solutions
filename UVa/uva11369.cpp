#include <bits/stdc++.h>
using namespace std;

// Shopaholic

int n;
int items[20003];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> items[i];
        sort(items, items+n);
        int ans = 0;
        for(int i = n % 3; i < n; i += 3)
            ans += items[i];
        cout << ans << endl;
    }
}