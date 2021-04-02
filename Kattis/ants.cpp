#include <bits/stdc++.h>
using namespace std;

// Ants

int l, n;
int ants[1000003];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> l >> n;
        for(int i = 0; i < n; i++)
            cin >> ants[i];
        sort(ants, ants+n);
        int ans1 = INT_MIN;
        for(int i = 0; i < n; i++)
            ans1 = max(ans1, min(ants[i], l-ants[i]));
        int ans2 = l - min(ants[0], l - ants[n-1]);
        cout << ans1 << " " << ans2 << endl;
    }
}