#include <bits/stdc++.h>
using namespace std;

// Antimonotonicity

int t, n;
int a[30003];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 1;
        bool inc = true;
        for(int i = 1; i < n; i++){
            if(inc && a[i] < a[i-1])
                ans++, inc = false;
            else if(!inc && a[i] > a[i-1])
                ans++, inc = true;
        }
        cout << ans << endl;
    }
}