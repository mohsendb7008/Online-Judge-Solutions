#include <bits/stdc++.h>
using namespace std;

// Provinces and Gold

int g, s, c, m;

int main(){
    cin >> g >> s >> c, m = 3 * g + 2 * s + c;
    if(m < 2)
        cout << "";
    else if(m < 5)
        cout << "Estate or ";
    else if(m < 8)
        cout << "Duchy or ";
    else
        cout << "Province or ";
    if(m < 3)
        cout << "Copper" << endl;
    else if(m < 6)
        cout << "Silver" << endl;
    else
        cout << "Gold" << endl;
}