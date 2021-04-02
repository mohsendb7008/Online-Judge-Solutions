#include <bits/stdc++.h>
using namespace std;

// Touchdown!

int n, a, ans = 20, down = true, l = 0, f = 0, pos = 0;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        ans += a;
        pos += a;
        if(f - l <= 3 && pos >= 10)
            l = f + 1, pos = 0;
        else if(f - l == 3 && pos < 10)
            down = false;
        if(ans <= 0){
            cout << "Safety" << endl;
            return 0;
        }
        if(ans >= 100 && down){
            cout << "Touchdown" << endl;
            return 0;
        }
        f++;
    }
    cout << "Nothing" << endl;
}