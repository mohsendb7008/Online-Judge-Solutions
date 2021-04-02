#include <bits/stdc++.h>
using namespace std;

// Karte

string s;
set<int> p, k, h, t;

set<int>& which(char c){
    if(c == 'P')
        return p;
    if(c == 'K')
        return k;
    if(c == 'H')
        return h;
    return t;        
}

int main(){
    cin >> s;
    string x;
    int y;
    for(int i = 0; i < s.size(); i += 3){
        x = s.substr(i, 3);
        y = atoi(x.substr(1, 2).c_str());
        set<int>& s = which(x[0]);
        if(s.find(y) != s.end()){
            cout << "GRESKA" << endl;
            return 0;
        }
        s.insert(y);
    }
    cout << 13 - p.size() << " " << 13 - k.size() << " " << 13 - h.size() << " " << 13 - t.size() << endl;
} 