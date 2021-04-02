#include <bits/stdc++.h>
using namespace std;

// Flow Shop

#define num long long int

int n, m;
num p[1003][1003], t[1003][1003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> p[i][j];
    t[0][0] = p[0][0];
    for(int j = 1; j < m; j++)
        t[0][j] = t[0][j-1] + p[0][j];
    for(int i = 1; i < n; i++){
        t[i][0] = t[i-1][0] + p[i][0];
        for(int j = 1; j < m; j++)
            t[i][j] = max(t[i-1][j], t[i][j-1]) + p[i][j];
    }
    for(int i = 0; i < n; i++)
        cout << t[i][m-1] << " ";
    cout << endl;
}