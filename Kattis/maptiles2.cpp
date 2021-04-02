#include <bits/stdc++.h>
using namespace std;

// Identifying Map Tiles

int main(){
    string s;
    cin >> s;
    cout << s.size() << " ";
    int n = s.size();
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')
            x += 1 << (n - i - 1);
        else if(s[i] == '2')
            y += 1 << (n - i - 1);
        else if(s[i] == '3')
            x += 1 << (n - i - 1), y += 1 << (n - i - 1);
    }
    cout << x << " " << y << endl;
}