#include <bits/stdc++.h>
using namespace std;

// Kemija

set<char> vowels{'a', 'e', 'i', 'o', 'u'};

int main(){
    string line;
    getline(cin, line);
    string ans = "";
    for(int i = 0; i < line.size(); i++){
        ans.push_back(line[i]);
        if(vowels.find(line[i]) != vowels.end())
            i += 2;
    }
    cout << ans << endl;
}