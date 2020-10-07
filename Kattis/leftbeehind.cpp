#include <bits/stdc++.h>
using namespace std;

// Left Beehind

int main(){
    int a, b;
    while(1){
        cin >> a >> b;
        if(!(a + b))
            break;
        if(a + b == 13)
            cout << "Never speak again." << endl;
        else if(a == b)
            cout << "Undecided." << endl;
        else if(a > b)
            cout << "To the convention." << endl;
        else
            cout << "Left beehind." << endl;
    }
}