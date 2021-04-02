#include <bits/stdc++.h>
using namespace std;

list<char> l;
list<char>::iterator it = l.begin();

int main(){
    int q;
    cin >>q;
    while(q--){
        string s;
        cin >> s;
        if(s == "insert"){
            char c;
            cin >> c;
            l.insert(it, c);
        }
        else if(s == "+"){
            if(it != l.end())
                it++;
        }
        else if(s == "-"){
            if(it != l.begin())
                it--;
        }
    }
    for(char c: l)
        cout << c;
    cout << endl;
}