#include <bits/stdc++.h>
using namespace std;

// Palindrome Substring

int n;
string s, t;
set<string> ans;

int main(){
    while(cin >> s){
        n = s.size(), ans.clear();
        for(int i = 0; i < n - 1; i++)
            if(s[i] == s[i + 1]){
                ans.insert(s.substr(i, 2));
                int x = i, y = i + 1;
                while(x - 1 >= 0 && y + 1 < n && s[x - 1] == s[y + 1]){
                    x--, y++;
                    ans.insert(s.substr(x, y - x + 1));
                }
            }
        for(int i = 1; i < n - 1; i++)
            if(s[i - 1] == s[i + 1]){
                ans.insert(s.substr(i-1, 3));
                int x = i - 1, y = i + 1;
                while(x - 1 >= 0 && y + 1 < n && s[x - 1] == s[y + 1]){
                    x--, y++;
                    ans.insert(s.substr(x, y - x + 1));
                }
            }
        for(string s : ans)
            cout << s << endl;
        cout << endl;
    }
}