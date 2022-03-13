// Sort of Sorting

#include <bits/stdc++.h>
using namespace std;

int n;
string a[203];
vector<pair<string, int>> v;

int main(){
    while(1){
        int n;
        cin >> n;
        if(!n){
            break;
        }
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> a[i];
            v.push_back({a[i].substr(0, 2), i});
        }
        stable_sort(v.begin(), v.end());
        for(auto it : v){
            cout << a[it.second] << endl;
        }
        cout << endl;
    }
}