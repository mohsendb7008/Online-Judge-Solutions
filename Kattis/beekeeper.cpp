#include <bits/stdc++.h>
using namespace std;

// Beekeeper

set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y'};

int process(string s){
    int ans = 0;
    for(int i = 0; i < s.size() - 1; i++)
        if(vowel.find(s[i]) != vowel.end() && s[i] == s[i+1])
            ans++;
    return ans;
}

int n;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        int mx = -1;
        string ans;
        while(n--){
            string c;
            cin >> c;
            int u = process(c);
            if(u > mx)
                mx = u, ans = c;
        }
        cout << ans << endl;
    }
}