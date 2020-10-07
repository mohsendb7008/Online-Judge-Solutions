#include <bits/stdc++.h>
using namespace std;

// Ornaments

double r, h, s;

int main(){
    while(1){
        cin >> r >> h >> s;
        if(!(r + h + s))
            break;
        double chord = sqrt(h * h - r * r);
        double ans = 2 * (chord  + r * (M_PI - asin(chord / h)));
        printf("%.2f\n", ans * (s + 100) / 100);
    }
}