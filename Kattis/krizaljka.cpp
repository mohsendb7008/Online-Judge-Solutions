#include <bits/stdc++.h>
using namespace std;

// Križaljka

string s, t;

int main(){
    cin >> s >> t;
    int i, j;
    bool found = false;
    for(int x = 0; x < s.size(); x++){
        if(found)
            break;
        for(int y = 0; y < t.size(); y++)
            if(s[x] == t[y]){
                i = x, j = y, found = true;
                break;
            }
    }
    for(int x = 0; x < t.size(); x++){
        for(int y = 0; y < s.size(); y++){
            if(x == j)
                cout << s[y];
            else if(y == i)
                cout << t[x];
            else
                cout << ".";
        }
        cout << endl;
    }
}