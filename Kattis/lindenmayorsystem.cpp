#include <bits/stdc++.h>
using namespace std;

// Linden Mayor System

int n, m;
char x, y;
map<char, string> rules;
string s;

string convert(){
    string ans = "";
    for(char c : s){
        if(rules.find(c) == rules.end())
            ans += c;
        else
            ans += rules[c];
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x >> y >> y >> s, rules[x] = s;
    cin >> s;
    while(m--)
        s = convert();
    cout << s << endl;
}