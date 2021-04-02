#include <bits/stdc++.h>
using namespace std;

// Soundex

map<char, string> sdx{
    {'A', ""},
    {'B', "1"},
    {'C', "2"},
    {'D', "3"},
    {'E', ""},
    {'F', "1"},
    {'G', "2"},
    {'H', ""},
    {'I', ""},
    {'J', "2"},
    {'K', "2"},
    {'L', "4"},
    {'M', "5"},
    {'N', "5"},
    {'O', ""},
    {'P', "1"},
    {'Q', "2"},
    {'R', "6"},
    {'S', "2"},
    {'T', "3"},
    {'U', ""},
    {'V', "1"},
    {'W', ""},
    {'X', "2"},
    {'Y', ""},
    {'Z', "2"}
};

int main(){
    string code;
    while(cin >> code){
        for(int i = 0; i < code.size(); i++){
            if(i > 0 && sdx[code[i-1]] == sdx[code[i]])
                continue;
            cout << sdx[code[i]];
        }
        cout << endl;
    }
}