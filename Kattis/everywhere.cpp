#include <bits/stdc++.h>
using namespace std;

// I've Been Everywhere, Man

set<string> names;

int main(){
    int t, n;
    string x;
    cin >> t;
    while(t--){
        cin >> n;
        names.clear();
        while(n--)
            cin >> x, names.insert(x);
        cout << names.size() << endl;
    }
}