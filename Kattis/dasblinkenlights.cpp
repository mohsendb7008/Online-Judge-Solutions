#include <bits/stdc++.h>
using namespace std;

// Das Blinkenlights

int p, q, s;

int gcd(int p, int q){
    if(p == 0)
        return q;
    return gcd(q % p, p);
}

int main(){
    cin >> p >> q >> s;
    cout << (((p * q) / gcd(min(p, q), max(p, q)) <= s) ? "yes" : "no") << endl;
}