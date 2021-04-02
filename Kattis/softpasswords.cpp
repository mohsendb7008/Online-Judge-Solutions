#include <bits/stdc++.h>
using namespace std;

// Soft Passwords

string s, p;

bool solve(){
    if(s == p)
        return true;
    for(char d = '0'; d <= '9'; d++)
        if(d + p == s || p + d == s)
            return true;
    string r = "";
    for(char c : p){
        if(c >= 'a' && c <= 'z')
            r += c - 'a' + 'A';
        else if(c >= 'A' && c <= 'Z')
            r += c - 'A' + 'a';
        else r += c;
    }
    return r == s;
}

int main(){
    cin >> s >> p;
    cout << (solve() ? "Yes" : "No") << endl;
}