#include <bits/stdc++.h>
using namespace std;

// Honeycomb Walk

inline void incOrPlace(map<pair<int, int>, int> &m, int x, int y, int value){
    pair<int, int> key = {x, y};
    if(m.find(key) == m.end())
        m[key] = value;
    else m[key] += value;
}

inline map<pair<int, int>, int> takeStep(map<pair<int ,int>, int> &honey){
    map<pair<int, int>, int> comb;
    for(pair<pair<int, int>, int> it : honey){
        int x = it.first.first;
        int y = it.first.second;
        int value = it.second;
        incOrPlace(comb, x+2, y, value);
        incOrPlace(comb, x-2, y, value);
        incOrPlace(comb, x+1, y+1, value);
        incOrPlace(comb, x-1, y+1, value);
        incOrPlace(comb, x+1, y-1, value);
        incOrPlace(comb, x-1, y-1, value);
    }
    return comb;
}

int ans[15];

int main(){
    map<pair<int, int>, int> larva;
    larva[{0, 0}] = 1;
    for(int i = 1; i <= 14; i++){
        larva = takeStep(larva);
        ans[i] = larva[{0, 0}];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}