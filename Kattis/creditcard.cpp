#include <bits/stdc++.h>
using namespace std;

// Credit Card Payment

double r, b, m;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> r >> b >> m;
        m = m * 100, b = b * 100;
        int cnt = 0;
        while(cnt + 1 <= 1200){
            if(fabs(b) < 1e-9)
                break;
            int interest = int(r * b / 100.0 + 0.5 + 1e-9);
            b += interest;
            b -= min(m, b);
            cnt++;
        }
        if(fabs(b) < 1e-9)
            cout << cnt << endl;
        else
            cout << "impossible" << endl;
    }
}
