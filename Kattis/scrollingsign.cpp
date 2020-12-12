#include <bits/stdc++.h>
using namespace std;

// Scrolling Sign

int n, k, w;
string s, t;

int main(){
    cin >> n;
    while(n--){
        cin >> k >> w;
        cin >> s, w--;
        while(w--){
            cin >> t;
            bool ok = 0;
            for(int i = k; i > 0; i--){
                if(t.substr(0, i) == s.substr(s.size() - i)){
                    s += t.substr(i);
                    ok = 1;
                    break;
                }
            }
            if(!ok)
                s += t;
        }
        cout << s.size() << endl;
    }
}