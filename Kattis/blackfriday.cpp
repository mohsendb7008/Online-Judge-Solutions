// Black Friday

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> m;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m[-x].push_back(i + 1);
    }
    for(auto it : m){
        if(it.second.size() == 1){
            cout << it.second.front() << endl;
            return 0;
        }
    }
    cout << "none" << endl;
}