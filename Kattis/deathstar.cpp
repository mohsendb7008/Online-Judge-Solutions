// Deathstar

#include <bits/stdc++.h>
using namespace std;

int n, m[1003][1003], a[1003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            a[i] = a[i] | m[i][j];
            a[j] = a[j] | m[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}