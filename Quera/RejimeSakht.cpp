#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> cnt;

int main(){
    cin >> s;
    for(char c : s)
        cnt[c]++;
    if(cnt['R'] >= 3 || (cnt['R'] >= 2 && cnt['Y'] >= 2) || (cnt['G'] == 0))
        cout << "nakhor lite" << endl;
    else
        cout << "rahat baash" << endl;
}