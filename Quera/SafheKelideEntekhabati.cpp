#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool caps = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == "CAPS"){
            caps = !caps;
            continue;
        }
        if(caps)
            cout << char('A' + (s[0] - 'a'));
        else
            cout << s;
    }
    cout << endl;
}