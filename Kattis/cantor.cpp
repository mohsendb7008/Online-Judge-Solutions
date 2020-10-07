#include <bits/stdc++.h>
using namespace std;

// Cantor

set<double> seen;

int main(){
    string s;
    while(1){
        cin >> s;
        if(s == "END")
            break;
        double x = stod(s);
        if(x == 0 || x == 1){
            cout << "MEMBER" << endl;
            continue;
        }
        seen.clear();
        bool member = 1;
        while(seen.find(x) == seen.end()){
            seen.insert(x);
            x *= 3.0;
            int d = static_cast<int>(x + 0.000000001);
            if(d == 1){
                member = 0;
                break;
            }
            x -= d;
            x = round(x * 1000000) / 1000000;
        }
        cout << (member ? "MEMBER" : "NON-MEMBER") << endl;
    }
}