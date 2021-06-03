#include <bits/stdc++.h>
using namespace std;

// A Rational Sequence 2

vector<string> split(const string& str, char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

vector<bool> signs;

int main(){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        cout << d << ' ';
        string s;
        cin >> s;
        vector<string> sp = split(s, '/');
        long int a = stoll(sp[0]);
        long int b = stoll(sp[1]);
        signs.clear();
        while(a != b){
            signs.push_back(b < a);
            if(b > a)
                b = b - a;
            else
                a = a - b;
        }
        reverse(signs.begin(), signs.end());
        int ans = 1;
        for(bool i : signs)
            ans = 2 * ans + i;
        cout << ans << '\n';
    }
}