#include <bits/stdc++.h>
using namespace std;

// String Popping

map<string, bool> m;

bool dp(string s){
    if(s.size() == 0)
        return true;
    if(s.size() == 1)
        return false;
    if(m.find(s) != m.end())
        return m[s];
    bool ans = false;
    int lptr = 0, rptr = 0;
    while(rptr < s.size()){
        if(s[lptr] == s[rptr])
            rptr++;
        else{
            if(rptr - lptr >= 2){
                string s2 = s.substr(0, lptr) + s.substr(rptr, s.size() - rptr);
                ans = ans || dp(s2);
                if(ans)
                    break;
            }
            lptr = rptr;
        }
    }
    if(rptr - lptr >= 2){
        string s2 = s.substr(0, lptr) + s.substr(rptr, s.size() - rptr);
        ans = ans || dp(s2);   
    }
    return m[s] = ans;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << dp(s) << endl;
    }
}