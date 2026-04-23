#include <iostream>
#include "SubstringHash.cpp"

using namespace std;

int main() {
    string input;
    cin >> input;
    SubstringHash<> substringHash1(input, 31, 1000000007, 'a' - 1);
    SubstringHash<> substringHash2(input, 37, 1000000009, 'a' - 1);
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << substringHash1.getHash(l, r - 1) * 1000000007 + substringHash2.getHash(l, r - 1) << endl;
    }
}