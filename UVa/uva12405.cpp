#include <bits/stdc++.h>
using namespace std;

// Scarecrow

int n;
string str;

int solve(int i){
    if(i == n)
        return 0;
    if(str[i] == '#')
        return solve(i+1);
    if(i >= n - 2)
        return 1;
    return 1 + solve(i+3);
}

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n;
        cin >> str;
        cout << "Case " << test << ": " << solve(0) << endl;
    }
}