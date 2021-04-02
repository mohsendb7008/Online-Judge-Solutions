#include <bits/stdc++.h>
using namespace std;

// Bela

int n;
char s;
map<char, int> p1{{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 20}, {'T', 10}, {'9', 14}};
map<char, int> p2{{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2}, {'T', 10}, {'9', 0}};

int main(){
    cin >> n >> s;
    n *= 4;
    int ans = 0;
    while(n--){
        char x, y;
        cin >> x >> y;
        if(y == s)
            ans += p1[x];
        else ans += p2[x];
    }
    cout << ans << endl;
}