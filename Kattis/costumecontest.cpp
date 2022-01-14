// Costume Contest

#include <bits/stdc++.h>
using namespace std;

map<string, int> freq;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        freq[s]++;
    }
    int min_freq = INT_MAX;
    for(auto it : freq){
        min_freq = min(min_freq, it.second);
    }
    for(auto it : freq){
        if(it.second == min_freq){
            cout << it.first << endl;
        }
    }
}