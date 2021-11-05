#include <bits/stdc++.h>
using namespace std;

#define num long long int

map<pair<num, num>, num> m;

num ask(num x, num y){
    auto it = m.find({x, y});
    if(it != m.end())
        return it->second;
    cout << "QUERY " << x << " " << y << endl;
    cout.flush();
    num ans;
    cin >> ans;
    m[{x, y}] = ans;
    return ans;
}

num findX(){
    num lo = -1000000000, hi = 1000000000;
    while(lo < hi){
        if(lo == hi-1){
            if(ask(hi, 0) < ask(lo, 0))
                lo = hi;
            break;
        }
        num m1 = lo + (hi - lo) / 3;
        num m2 = hi - (hi - lo) / 3;
        num a1 = ask(m1, 0);
        num a2 = ask(m2, 0);
        if(a1 == a2){
            lo = m1 + 1;
            hi = m2 - 1;
        }
        else if(a1 > a2){
            lo = m1 + 1;
        }
        else{
            hi = m2 - 1;
        }
    }
    return lo;
}


int main(){
    num x = findX();
    num y = -1000000000 + ask(x, -1000000000);
    cout << "GUESS " << x << " " << y << endl;
    cout.flush(); 
}