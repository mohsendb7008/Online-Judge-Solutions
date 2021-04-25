#include <bits/stdc++.h>
using namespace std;

// Forced Choice

int main(){
    int p, s;
    cin >> p >> p >> s;
    while(s--){
        int m, x;
        set<int> s;
        cin >> m;
        while(m--)
            cin >> x, s.insert(x);
        cout << (s.find(p) == s.end() ? "REMOVE\n" : "KEEP\n");
    }
}