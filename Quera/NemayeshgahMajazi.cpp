#include <bits/stdc++.h>
using namespace std;

int k, c = 1;

int main() {
    cin >> k;
    for(int i = 0; i < 4; i++) {
        cout << "########.......########" << endl;
        cout << "#";
        if (c <= k) {
            cout << "ghorfe" << c;
            c++;
        }
        else
            cout << ".......";
        cout << ".......";
        if (c <= k) {
            cout << "ghorfe" << c;
            c++;
        }
        else
            cout << ".......";
        cout << "#" << endl;
    }
    cout << "#######################" << endl;
}