#include <bits/stdc++.h>
using namespace std;

// Trik

int main(){
    string s;
    cin >> s;
    int ans = 1;
    for(char c : s){
        if(c == 'A'){
            if(ans == 1)
                ans = 2;
            else if(ans == 2)
                ans = 1;
        }
        else if(c == 'B'){
            if(ans == 2)
                ans = 3;
            else if(ans == 3)
                ans = 2;
        }
        else if(c == 'C'){
            if(ans == 1)
                ans = 3;
            else if(ans == 3)
                ans = 1;
        }
    }
    cout << ans << endl;
}