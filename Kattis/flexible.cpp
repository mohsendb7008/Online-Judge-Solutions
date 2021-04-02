#include <bits/stdc++.h>
using namespace std;

// Flexible Spaces

int w, p;
vector<int> v;
set<int> ans;

int main(){
    cin >> w >> p;
    int x;
    v.push_back(0);
    while(p--)
        cin >> x, v.push_back(x);
    v.push_back(w);
    for(int i = 1; i < v.size(); i++)
        for(int j = 0; j < i; j++)
            ans.insert(v[i] - v[j]);
    for(int i : ans)
        cout << i << " ";
    cout << endl;
}