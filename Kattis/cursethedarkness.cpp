#include <bits/stdc++.h>
using namespace std;

// Curse the Darkness

#define EPS 1e-9

int m, n;
double a, b, x, y;
bool ans;

int main(){
    cin >> m;
    while(m--){
        ans = false;
        cin >> a >> b >> n;
        while(n--){
            cin >> x >> y;
            if(hypot(x - a, y - b) < 8.0 + EPS)
                ans = true;
        }
        cout << (ans ? "light a candle" : "curse the darkness") << endl;
    }
}