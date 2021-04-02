#include <bits/stdc++.h>
using namespace std;

// Recount

map<string, int> votes;

int main(){
    string s;
    while(1){
        getline(cin, s);
        if(s == "***")
            break;
        votes[s]++;
    }
    int maxv = 0;
    string winner;
    for(auto it : votes)
        maxv = max(maxv, it.second);
    int winners = 0;
    for(auto it : votes)
        if(it.second == maxv)
            winners++, winner = it.first;
    if(winners == 1)
        cout << winner << endl;
    else
        cout << "Runoff!" << endl;
}