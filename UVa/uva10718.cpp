#include <bits/stdc++.h>
using namespace std;

// Bit Mask

#define uint unsigned int

int main(){
    uint N, L, U;
    while(cin >> N){
        cin >> L >> U;
        uint M = 0;
        for(int e = 31; e >= 0; e--){
            uint p = 1 << e;
            if(p > U)
                continue;
            if((p <= L) || !(N & p)){
                M |= p;
                L -= min(L, p);
                U -= min(U, p);
            }
        }
        cout << M << endl;
    }
}