#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a[2003];

vector<int> solve(int l, int r){
    if(l == r)
        return a[l];
    int mid = (l + r) / 2;
    vector<int> lv = solve(l, mid), rv = solve(mid + 1, r), result;
    int lptr = 0, rptr = 0;
    while(lptr < lv.size() && rptr < rv.size()){
        if(lv[lptr] < rv[rptr])
            result.push_back(lv[lptr++]);
        else
            result.push_back(rv[rptr++]);
    }
    while(lptr < lv.size())
        result.push_back(lv[lptr++]);
    while(rptr < rv.size())
        result.push_back(rv[rptr++]);
    return result;
}

void print(vector<int> v){
    for(int a : v)
        cout << a << " ";
    cout << endl;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    print(solve(0, k - 1));
}