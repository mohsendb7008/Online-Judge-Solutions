#include <bits/stdc++.h>
using namespace std;

// Foreign Exchange

map<int, multiset<int>> target;

int main(){
    int n;
    while(1){
        cin >> n;
        if(!n)
            break;
        target.clear();
        int x, y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            target[x].insert(y);
        }
        bool ans = true;
        for(pair<int, multiset<int>> p : target){
            int origin = p.first;
            for(int destination : p.second){
                multiset<int>& there = target[destination];
                auto it = there.find(origin);
                if(it == there.end()){
                    ans = false;
                    break;
                }
                there.erase(it);
            }
            p.second.clear();
            if(!ans)
                break;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}