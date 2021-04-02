#include <bits/stdc++.h>
using namespace std;

// Yin and Yang Stones

string s;

int main(){
    cin >> s;
    cout << (count(s.begin(), s.end(), 'W') == count(s.begin(), s.end(), 'B')) << endl;
}