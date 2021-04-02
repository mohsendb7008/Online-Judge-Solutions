#include <bits/stdc++.h>
using namespace std;

int n;
string s, s1, s2, s3, s4;

bool matchh(string& t){
    for(int i = 0; i < n; i++){
        if(s[i] == '?')
            continue;
        if(s[i] != t[i])
            return 0;
    }
    return 1;
}

int main(){
    cin >> s, n = s.size();
    s1.resize(n), s2.resize(n), s3.resize(n), s4.resize(n);
    for(int i = 0; i < n; i += 2)
        s1[i] = ((i / 2) % 2) ? 'a' : 'b';
    for(int i = 1; i < n; i += 2)
        s1[i] = (((i - 1) / 2) % 2) ? 'a' : 'b';
    for(int i = 0; i < n; i += 2)
        s2[i] = ((i / 2) % 2) ? 'a' : 'b';
    for(int i = 1; i < n; i += 2)
        s2[i] = (((i - 1) / 2) % 2) ? 'b' : 'a';
    for(int i = 0; i < n; i += 2)
        s3[i] = ((i / 2) % 2) ? 'b' : 'a';
    for(int i = 1; i < n; i += 2)
        s3[i] = (((i - 1) / 2) % 2) ? 'a' : 'b';
    for(int i = 0; i < n; i += 2)
        s4[i] = ((i / 2) % 2) ? 'b' : 'a';
    for(int i = 1; i < n; i += 2)
        s4[i] = (((i - 1) / 2) % 2) ? 'b' : 'a';
    cout << matchh(s1) + matchh(s2) + matchh(s3) + matchh(s4) << endl;
}