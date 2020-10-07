#include <bits/stdc++.h>
using namespace std;

int n;
string ss;
set<char> s;

int main(){
    cin >> n >> ss;
    for(char c : ss){
        if(c >= 'A' && c <= 'Z')
            s.insert(c - 'A' + 'a');
        else if(c >= 'a' && c <= 'z')
            s.insert(c);
    }
    bool ok = true;
    for(char c = 'a'; c <= 'z'; c++)
        if(s.find(c) == s.end()){
            ok = false;
            break;
        }  
    cout << (ok ? "YES" : "NO") << endl;
}