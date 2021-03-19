#include <bits/stdc++.h>
using namespace std;

// Accounting

int n, q, d = 0;
map<int, int> m;

int main(){
    cin >> n >> q;
    while(q--){
        string s;
        int x, y;
        cin >> s >> x;
        if(s == "SET")
            cin >> y, m[x] = y;
        else if(s == "RESTART")
            d = x, m.clear();
        else if(s == "PRINT"){
            if(m.find(x) == m.end())
                cout << d << endl;
            else
                cout << m[x] << endl;
        }
    }
}