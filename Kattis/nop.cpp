#include <bits/stdc++.h>
using namespace std;

// NOP

string s;
int ptr = 0, ans = 0;

int main(){
    cin >> s;
    for(char c : s){
        if(c >= 'A' && c <= 'Z' && ptr % 4)
            ans += 4 - ptr % 4, ptr += 4 - ptr % 4;
        ptr++;
    }
    cout << ans << endl;
}