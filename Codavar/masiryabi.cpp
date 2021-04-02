#include <bits/stdc++.h>
using namespace std;

// Masiryabi

#define num long long int

int n;
num g[12 + 3][12 + 3];
num l;
vector<int> v;

int main(){
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int i = 1; i < n; i++)
        v.push_back(i);
    do{
        num sum = g[0][v[0]];
        for(int i = 0; i < n - 2; i++)
            sum += g[v[i]][v[i + 1]];
        sum += g[0][v.back()];
        if(sum == l){
            cout << "possible" << endl;
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << "impossible" << endl;
}