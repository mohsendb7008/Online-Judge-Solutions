#include <bits/stdc++.h>
using namespace std;

// ICPC Awards

int n;
string uni, team;
set<string> s;

int main(){
    cin >> n;
    int it = 12;
    while(it){
        cin >> uni >> team;
        if(s.find(uni) == s.end()){
            cout << uni << " " << team << endl;
            s.insert(uni);
            it--;
        }
    }
}