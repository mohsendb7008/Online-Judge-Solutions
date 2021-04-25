#include <bits/stdc++.h>
using namespace std;

// Boat Parts

int n, p;
set<string> items;

int main(){
    cin >> p >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        items.insert(s);
        if(items.size() == p){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "paradox avoided\n";
}