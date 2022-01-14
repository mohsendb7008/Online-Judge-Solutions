// Knot Knowledge

#include <bits/stdc++.h>
using namespace std;

int n;
set<int> a;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        a.erase(x);
    }
    cout << *a.begin() << endl;
}