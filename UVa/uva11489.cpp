#include <bits/stdc++.h>
using namespace std;

// Integer Game

bool solve(int a, int b, int c){
    bool ans = a % 2;
    int sum = (b + 2 * c) % 3;
    if(sum == 0)
        return ans;
    if(sum == 1){
        if(b)
            return !ans;
        return false;
    }
    if(c)
        return !ans;
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        string s;
        cin >> s;
        int a[3];
        fill_n(a, 3, 0);
        for(char c : s)
            a[(c - '0')%3]++;
        cout << "Case " << test << ": " << (solve(a[0], a[1], a[2]) ? "S" : "T") << endl;
    }
}