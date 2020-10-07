#include <bits/stdc++.h>
using namespace std;

// Autori

int main(){
    string s, token;
    cin >> s;
    stringstream ss(s);
    while(getline(ss, token, '-'))
        cout << token[0];
}