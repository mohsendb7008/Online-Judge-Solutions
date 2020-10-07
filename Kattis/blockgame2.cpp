#include <bits/stdc++.h>
using namespace std;

// Block Game

bool solve(long long int a, long long int b){
    if(!(b % a))
        return true;
    if(b / a > 1)
        return true;
    return !solve(b % a, a);
}

int main(){
    long long int a, b;
    cin >> a >> b;
    cout << (solve(min(a, b), max(a, b)) ? "win" : "lose") << endl;
}