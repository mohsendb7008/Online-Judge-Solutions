#include <bits/stdc++.h>
using namespace std;

// Combination Lock

int main(){
    int s, a, b, c;
    while(1){
        cin >> s >> a >> b >> c;
        if(s + a + b + c == 0)
            break;
        cout << (120 + (s - a + 40) % 40 + (b - a + 40) % 40 + (b - c + 40) % 40) * 9 << endl;
    }
}