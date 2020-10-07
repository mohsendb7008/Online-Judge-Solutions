#include <bits/stdc++.h>
using namespace std;

// Competitive Arcade Basketball

int n, p, m;
map<string, int> sc;

int main(){
    cin >> n >> p >> m;
    string s;
    int c;
    while(n--)
        cin >> s;
    bool win = false;
    while(m--){
        cin >> s >> c;
        sc[s] += c;
        if(sc[s] >= p){
            win = true;
            sc[s] = INT_MIN;
            cout << s << " wins!" << endl; 
        }
    }
    if(!win)
        cout << "No winner!" << endl;
}