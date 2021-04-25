#include <bits/stdc++.h>
using namespace std;

// Stopwatch

int main(){
    int n;
    cin >> n;
    if(n % 2){
        cout << "still running" << endl;
        return 0;
    }
    n /= 2;
    int ans = 0;
    while(n--){
        int x, y;
        cin >> x >> y;
        ans += y - x;
    }
    cout << ans << endl;
}