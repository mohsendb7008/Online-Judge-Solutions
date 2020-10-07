#include <bits/stdc++.h>
using namespace std;

// Guessing Game

int main(){
    int g;
    string x;
    while(1){
        cin >> g;
        cin.ignore();
        if(!g)
            break;
        int lo = 1, hi = 10;
        getline(cin, x);
        bool honest = true;
        while(1){
            if(x == "too high")
                hi = min(hi, g - 1);
            if(x == "too low")
                lo = max(lo, g + 1);
            if(lo > hi)
                honest = false;
            if(x == "right on"){
                if(!(g >= lo && g <= hi))
                    honest = false;
                break;
            }
            cin >> g;
            cin.ignore();
            getline(cin, x);
        }
        cout << (honest ? "Stan may be honest" : "Stan is dishonest") << endl;
    }
}