#include <bits/stdc++.h>
using namespace std;

// Just a Minute

int n, M = 0, S = 0;

int main(){
    cin >> n;
    while(n--){
        int m, s;
        cin >> m >> s;
        M += 60 * m, S += s;
    }
    double ans = double(S) / M;
    if(ans < 1 + 1e-9)
        cout << "measurement error" << endl;
    else
        cout << fixed << setprecision(10) << ans << endl;
}