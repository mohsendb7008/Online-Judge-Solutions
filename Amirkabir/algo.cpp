#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> ss;

int main(){
    cin >> n;
    while(n--){
        bool ok = 0;
        for(int i = 0; i < 3; i++){
            cin >> s;
            if(ok)
                continue;
            if(ss.find(s) == ss.end()){
                cout << s << endl;
                ss.insert(s);
                ok = 1;
            }
        }
        if(!ok)
            cout << "Unlucky" << endl;
    }
}