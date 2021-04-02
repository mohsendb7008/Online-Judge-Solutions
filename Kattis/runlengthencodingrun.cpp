#include <bits/stdc++.h>
using namespace std;

// Run-Length Encoding, Run!

string decode(string code){
    string ans = "";
    for(int i = 0; i < code.size(); i += 2){
        char c = code[i];
        int r = code[i + 1] - '0';
        while(r--)
            ans += c;
    }
    return ans;
}

string encode(string code){
    string ans = "";
    int i = 0;
    while(i < code.size()){
        char c = code[i];
        int r = 1;
        while(i + 1 < code.size() && code[i+1] == code[i])
            i++, r++;
        ans += c, ans += to_string(r);
        i++;
    }
    return ans;
}

int main(){
    char c;
    string code;
    cin >> c >> code;
    if(c == 'D')
        cout << decode(code) << endl;
    else
        cout << encode(code) << endl;
}