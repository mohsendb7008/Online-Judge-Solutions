#include <bits/stdc++.h>
using namespace std;

// Amalgamated Artichokes

double p, a, b, c, d;
int n;

inline double f(int k){
    return p * (sin(a * k + b)  + cos(c * k + d) + 2);
}

int main(){
    cout << fixed << setprecision(10);
    cin >> p >> a >> b >> c >> d >> n;
    double mt = f(1), ans = 0;
    for(int i = 2; i <= n; i++){
        double curr = f(i);
        if(curr < mt)
            ans = max(ans, mt - curr);
        mt = max(mt, curr);
    }
    cout << ans << endl;
}