// Cinema Crowds 2

#include <bits/stdc++.h>
using namespace std;

const int maxn = 53;

int n, m, a[53];

int main(){
    int sat = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        if(sat + a[i] > n){
            cout << m - i << endl;
            return 0;
        }
        sat += a[i];
    }
    cout << 0 << endl;
}