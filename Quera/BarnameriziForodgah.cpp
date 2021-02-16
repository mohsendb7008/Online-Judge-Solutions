#include <bits/stdc++.h>
using namespace std;

int q, k, ap;
set<int> airplanes;

int main(){
    cin >> q >> k;
    while(q--){
        cin >> ap;
        auto lo = airplanes.lower_bound(ap), hi = airplanes.upper_bound(ap);
        if(*lo == ap){
            cout << "Permission Denied!" << endl;
            continue;
        }
        bool grant = true;
        if(lo != airplanes.begin() && ap - *prev(lo) < k)
            grant = false;
        if(hi != airplanes.end() && *hi - ap < k)
            grant = false;
        if(grant)
            airplanes.insert(ap), cout << "Permission Granted!" << endl;
        else 
            cout << "Permission Denied!" << endl;
    }
}