#include <bits/stdc++.h>
using namespace std;

// Paludarium

#define num long long int

const int maxw = 5e5 + 3;

int w;
num h, b[maxw], air = 0;

inline num water(num l){
    num ans = 0;
    for(int i = 0; i < w; i++)
        ans += max(0ll, l - b[i]);
    return ans;
}

inline num diff(num water){
    return abs(air - 2 * water);
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < w; i++)
        cin >> b[i], air += h - b[i];
    num minimum = *min_element(b, b + w);
    num lo = minimum, hi = h;
    while(lo < hi){
        num mid = (lo + hi) / 2 + (lo + hi) % 2; 
        num f = water(mid);
        if(f <= air / 2)
            lo = mid;
        else
            hi = mid - 1;
    }
    if(lo < h && diff(water(lo + 1)) < diff(water(lo)))
        lo++;
    if(lo == minimum)
        cout << "0 0" << endl;
    else
        cout << lo << " " << water(lo) << endl;
}