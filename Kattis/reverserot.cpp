#include <bits/stdc++.h>
using namespace std;

// Reverse Rot

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
map<char, int> ind;

int main(){
    for(int i = 0; i < 28; i++)
        ind[alphabet[i]] = i;
    while(1){
        int n;
        cin >> n;
        if(!n)
            break;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for(char c : s)
            cout << alphabet[(ind[c] + n) % 28];
        cout << endl;
    } 
}