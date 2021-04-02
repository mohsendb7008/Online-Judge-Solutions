#include <bits/stdc++.h>
using namespace std;

// A New Alphabet

map<char, string> m{
    {'a', "@"},
    {'b', "8"},
    {'c', "("},
    {'d', "|)"},
    {'e', "3"},
    {'f', "#"},
    {'g', "6"},
    {'h', "[-]"},
    {'i', "|"},
    {'j', "_|"},
    {'k', "|<"},
    {'l', "1"},
    {'m', "[]\\/[]"},
    {'n', "[]\\[]"},
    {'o', "0"},
    {'p', "|D"},
    {'q', "(,)"},
    {'r', "|Z"},
    {'s', "$"},
    {'t', "']['"},
    {'u', "|_|"},
    {'v', "\\/"},
    {'w', "\\/\\/"},
    {'x', "}{"},
    {'y', "`/"},
    {'z', "2"}
};

string s;

int main(){
    getline(cin, s);
    for(char c : s){
        if(c >= 'a' && c <= 'z')
            cout << m[c];
        else if(c >= 'A' && c <= 'Z')
            cout << m[c-'A'+'a'];
        else
            cout << c;
    }
    cout << endl;
}