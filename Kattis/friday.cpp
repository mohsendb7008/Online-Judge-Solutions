#include <bits/stdc++.h>
using namespace std;

// Friday the 13th

int main(){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d >> d;
        int day = 0, ans = 0;
        while(d--){
            int x;
            cin >> x;
            if(x >= 13 && (day + 12) % 7 == 5)
                ans++;
            day += x;
        }
        cout << ans << endl;
    }
}