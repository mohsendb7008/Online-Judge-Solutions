#include <bits/stdc++.h>
using namespace std;

// Incognito

map<string, int> a;

int main(){
    int t, n;
    string x;
    cin >> t;
    while(t--){
        cin >> n;
        a.clear();
        while(n--)
            cin >> x >> x, a[x]++;
        long long int ans = 1;
        for(pair<string, int> p : a)
            ans *= p.second + 1;
        cout << ans - 1 << endl; 
    }
}