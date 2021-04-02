#include <bits/stdc++.h>
using namespace std;

// Joint Attack

#define num long long int

int n;
num co[43];

pair<num, num> rec(int i){
    if(i == n - 1)
        return {co[i], 1};
    auto nex = rec(i + 1);
    return {co[i] * nex.first + nex.second, nex.first};
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> co[i];
    auto ans = rec(0);
    cout << ans.first << '/' << ans.second << endl;
}