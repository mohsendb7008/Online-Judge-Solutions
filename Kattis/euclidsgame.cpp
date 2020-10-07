#include <bits/stdc++.h>
using namespace std;

// Euclid's Game

bool solve(int a, int b){
    if(!(b % a))
        return true;
    if(b / a > 1)
        return true;
    return !solve(b % a, a);
}

int main(){
    int n, m;
    while(1){
        cin >> n >> m;
        if(!(n+m))
            break;
        cout << (solve(min(n, m), max(n, m)) ? "Stan wins" : "Ollie wins") << endl;
    }
}