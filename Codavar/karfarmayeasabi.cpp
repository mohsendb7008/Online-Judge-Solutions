#include <bits/stdc++.h>
using namespace std;

// Karfarmaye Asabi

int a, b, c;
string fired = "You're fired!";

int gcd(int a, int b){
    int mi = min(a, b), mx = max(a, b);
    if(mi == 0)
        return mx;
    return gcd(mx % mi, mi);
}

string fraction(int a, int b){
    bool pos = (a * b >= 0);
    a = abs(a), b = abs(b);
    int g = gcd(a, b);
    if(pos)
        return to_string(a / g) + '/' + to_string(b / g);
    else
        return '-' + to_string(a / g) + '/' + to_string(b / g);
}

string solve(){
    if(a == 0 && b == 0)
        return fired;
    else if(a == 0)
        return fraction(-c, b);
    int delta = b * b - 4 * a * c;
    if(delta < 0)
        return fired;
    else if(delta == 0)
        return fraction(-b, 2 * a);
    else
        return fraction(-b, a);
}

int main(){
    cin >> a >> b >> c;
    cout << solve() << endl;
}