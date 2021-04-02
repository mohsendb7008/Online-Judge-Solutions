#include <bits/stdc++.h>
using namespace std;

// Hot Hike

int n;
int t[53];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    int ans = INT_MAX, d;
    for(int i = 0; i < n - 2; i++){
        int it = max(t[i], t[i+2]);
        if(it < ans){
            ans = it;
            d = i;
        }
    }
    cout << d + 1 << " " << ans << endl;
}