#include <bits/stdc++.h>
using namespace std;

// Hangman

string s, t;
set<char> u, v;

int main(){
    cin >> s >> t;
    for(char c : s)
        u.insert(c);
    for(char c : t){
        if(u.find(c) != u.end()){
            u.erase(c);
            if(u.empty())
                break;
        }
        else{
            v.insert(c);
            if(v.size() == 10){
                cout << "LOSE" << endl;
                return 0;
            }
        }
    } 
    cout << "WIN" << endl;
}