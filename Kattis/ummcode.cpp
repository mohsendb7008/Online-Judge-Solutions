#include <bits/stdc++.h>
using namespace std;

// Umm Code

string code = "";

void build(string s){
    string t = "";
    for(char c : s)
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            if(!(c == 'u' || c == 'm'))
                return;
            t += c;
        }
    code += t;
}

char decode(string s){
    char ans = 0;
    int mul = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'u')
            ans += mul;
        mul *= 2;
    }
    return ans;    
}

int main(){
    string word;
    while(cin >> word)
        build(word);
    for(int i = 0; i < code.size(); i += 7)
        cout << decode(code.substr(i, 7));
    cout << endl;
}