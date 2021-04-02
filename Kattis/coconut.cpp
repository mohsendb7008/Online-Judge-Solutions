#include <bits/stdc++.h>
using namespace std;

// Coconut Splat

int n, s;
list<pair<int, char>> players;
list<pair<int, char>>::iterator it;

inline list<pair<int, char>>::iterator adv(list<pair<int, char>>::iterator it){
    auto nex = next(it);
    if(nex == players.end())
        return players.begin();
    return nex;
}

inline void play(){
    int k = s - 1;
    while(k--)
        it = adv(it);
}

int main(){
    cin >> s >> n;
    for(int i = 1; i <= n; i++)
        players.push_back({i, 'T'});
    it = players.begin();
    while(players.size() > 1){
        play();
        int id = it->first;
        if(it->second == 'T'){
            auto save = adv(it);
            players.erase(it);
            it = save;
            it = players.insert(it, {id, 'F'});
            it = players.insert(it, {id, 'F'});
        }
        else if(it->second == 'F'){
            auto save = adv(it);
            players.erase(it);
            it = save;
            it = players.insert(it, {id, 'P'});
            it = adv(it);
        }
        else{
            auto save = adv(it);
            players.erase(it);
            it = save;
        }
    }
    cout << players.begin()->first << endl;
}