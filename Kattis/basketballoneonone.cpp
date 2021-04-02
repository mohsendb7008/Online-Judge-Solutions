#include <bits/stdc++.h>
using namespace std;

// Basketball One-on-One

int a = 0, b = 0;

int main(){
    char c;
    int s;
    while(cin >> c >> s){
        if(c == 'A')
            a += s;
        else b += s; 
    }
    cout << (a > b ? 'A' : 'B') << endl; 
}