#include <bits/stdc++.h>
using namespace std;

map<char, int> cnt;
set<char> dup;

string compress(string s){
    cnt.clear();
    for(char c : s)
        cnt[c]++;
    string ans = "";
    dup.clear();
    for(char c : s){
        if(dup.find(c) != dup.end())
            continue;
        ans.push_back(c);
        dup.insert(c);
    }
    for(auto it : cnt)
        if(it.second > 1)
            ans += to_string(it.second);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    cin >> s;
    while(1){
        string t = compress(s);
        if(t == s)
            break;
        s = t;    
    }
    cout << s << endl;
}