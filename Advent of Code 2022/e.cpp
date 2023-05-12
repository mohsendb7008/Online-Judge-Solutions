#include <bits/stdc++.h>
using namespace std;

string str[10]{
    "RSLFQ",
    "NZQGPT",
    "SMQB",
    "TGZJHCBQ",
    "PHMBNFS",
    "PCQNSLVG",
    "WCF",
    "QHGZWVPM",
    "GZDLCNR"
};
stack<char> st[10];

inline void move(int i, int j){
    if(st[i].empty()){
        return;
    }
    int elm = st[i].top();
    st[i].pop();
    st[j].push(elm);
}

int main(){
    for(int i = 0; i < 10; i++){
        for(char c: str[i]){
            st[i].push(c);
        }
    }
    string d;
    int c, x, y;
    while(cin >> d >> c >> d >> x >> d >> y){
        while(c--){
            move(x-1, y-1);
        }
    }
    for(int i = 0; i < 10; i++){
        if(!st[i].empty())
            cout << st[i].top();
    }
    cout << endl;
}