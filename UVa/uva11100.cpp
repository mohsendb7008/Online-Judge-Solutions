#include <bits/stdc++.h>
using namespace std;

// The Trip, 2007

int n;
map<int, int> bags;
vector<int> pieces[10003];

int main(){
    bool first = true;
    while(1){
        cin >> n;
        if(!n)
            break;
        if(!first)
            cout << endl;
        first = false;
        bags.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            bags[x]++;
        }
        int k = max_element(bags.begin(), bags.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        })->second;
        cout << k << endl;
        for(int i = 0; i < k; i++)
            pieces[i].clear();
        int ptr = 0;
        for(pair<int, int> bag : bags)
            for(int i = 0; i < bag.second; i++){
                pieces[ptr].push_back(bag.first);
                ptr = (ptr + 1) % k;
            }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < pieces[i].size() - 1; j++)
                cout << pieces[i][j] << " ";    
            cout << pieces[i][pieces[i].size()-1] << endl;
        }
    }
}