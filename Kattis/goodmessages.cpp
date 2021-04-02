#include <bits/stdc++.h>
using namespace std;

// Good Messages

set<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

bool is_vowel(char c){
    return vowels.find(c) != vowels.end();
}

int k, good = 0, bad = 0;

string encode(string in){
    for(int i = 0; i < in.size(); i++)
        in[i] = (in[i] - 'a' + k) % 26 + 'a';
    int v = count_if(in.begin(), in.end(), is_vowel);
    int s = in.size() - v;
    if(v >= (s + 1) / 2)
        bad++;
    else
        good++;
    return in;
}

int main(){
    cin >> k;
    string s;
    cin >> s;
    int n;
    cin >> n;
    while(n--)
        s = encode(s);
    cout << (good > bad ? "Boris" : "Colleague") << endl;
}