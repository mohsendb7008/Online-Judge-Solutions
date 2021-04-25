#include <bits/stdc++.h>
using namespace std;

// Encoded Message

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = sqrt(s.size()) + 0.5;
        for(int j = n-1; j >= 0; j--)
            for(int i = 0; i < n; i++)
                cout << s[i * n + j];
        cout << '\n';
    }
}