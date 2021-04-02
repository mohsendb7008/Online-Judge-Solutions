#include <bits/stdc++.h>
using namespace std;

// The Playboy Chimp

int n, q;
vector<int> girls;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        girls.push_back(x);
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto lo = lower_bound(girls.begin(), girls.end(), x);
        if(lo == girls.begin())
            cout << "X ";
        else cout << *prev(lo) << " ";
        auto hi = upper_bound(girls.begin(), girls.end(), x);
        if(hi == girls.end())
            cout << "X" << endl;
        else cout << *hi << endl;
    }
}