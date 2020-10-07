#include <bits/stdc++.h>
using namespace std;

// Stone Game

int main(){
    long long int n;
    while(cin >> n){
        if(!n)
            break;
        long long int ans, x;
        cin >> ans;
        n--;
        while(n--)
            cin >> x, ans = ans ^ x;
        cout << (ans ? "Yes" : "No") << endl;
    }
}