#include <bits/stdc++.h>
using namespace std;

// Peragrams

string s;
map<char, int> counts;

int main(){
    cin >> s;
    for(char c : s)
        counts[c]++;
    int odds = 0;
    for(auto it : counts)
        if(it.second % 2)
            odds++;
    cout << max(0, odds-1) << endl;
}