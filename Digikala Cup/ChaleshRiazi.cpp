#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
bool first = 1;

void track(int i, int d){
    if(i == n){
        if(!first)
            cout << ',';
        cout << s;
        first = 0;
        return;
    }
    if(d - k >= 0){
        s.push_back(d - k + '0');
        track(i + 1, d - k);
        s.pop_back();
    }
    if(d + k <= 9){
        s.push_back(d + k + '0');
        track(i + 1, d + k);
        s.pop_back();
    }
}

int main(){
    cin >> n >> k;
    s = "";
    for(int d = 1; d <= 9; d++){
        s.push_back(d + '0');
        track(1, d);
        s.pop_back();
    }
    cout << endl;
}