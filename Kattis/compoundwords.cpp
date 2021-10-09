#include <bits/stdc++.h>

using namespace std;

// Compound Words

vector<string> words;
set<string> ans;

int main() {
    string s;
    while(cin >> s)
        words.push_back(s);
    for(int i = 0; i < words.size(); i++)
        for(int j = 0; j < words.size(); j++)
            if (i != j)
                ans.insert(words[i] + words[j]);
    for(string w: ans)
        cout << w << endl;
}