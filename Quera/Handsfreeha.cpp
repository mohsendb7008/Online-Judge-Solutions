#include <bits/stdc++.h>
using namespace std;

char A, B, C, D;

int main() {
    cin >> A >> B >> C >> D;
    if (A == B || A == D || C == D || C == B)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}