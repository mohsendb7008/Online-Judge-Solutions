#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    int t;
    cin >> t;
    while(t--){
        int px, py;
        cin >> px >> py >> s;
        int r = 0, l = 0, u = 0, d = 0;
        for(char c : s){
            if(c == 'R')
                r++;
            if(c == 'L')
                l++;
            if(c == 'U')
                u++;
            if(c == 'D')
                d++;
        }
        if(px >= -l && px <= r && py >= -d && py <= u)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}