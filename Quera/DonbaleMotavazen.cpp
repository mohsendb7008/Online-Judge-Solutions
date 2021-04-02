#include <bits/stdc++.h>
using namespace std;

string s;
int a = 0, b = 0;

int main(){
    cin >> s;
    for(char c : s){
        if(c == '(')
            a++;
        else if(a)
            a--;
        else
            b++;
    }
    cout << (a + 1) / 2 + (b + 1) / 2 << endl;
}