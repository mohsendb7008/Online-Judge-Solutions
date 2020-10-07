#include <bits/stdc++.h>
using namespace std;

// DRM Messages

int main(){
    string s;
    cin >> s;
    string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2, s.size() - s.size() / 2);
    int r1 = 0, r2 = 0;
    for(char c : s1)
        r1 += c - 'A';
    for(char c : s2)
        r2 += c - 'A';
    for(int i = 0; i < s1.size(); i++)
        s1[i] = (s1[i] - 'A' + r1) % 26 + 'A';
    for(int i = 0; i < s2.size(); i++)
        s2[i] = (s2[i] - 'A' + r2) % 26 + 'A';
    for(int i = 0; i < s1.size(); i++)
        cout << char((s1[i] - 'A' + s2[i] - 'A') % 26 + 'A');
    cout << endl;
}