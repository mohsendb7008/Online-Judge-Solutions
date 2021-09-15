#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    for(long long int i = 1; i * i <= 1000000000; i++)
        v.push_back(i * i);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << distance(lower_bound(v.begin(), v.end(), l), upper_bound(v.begin(), v.end(), r)) << endl; 
    }
}