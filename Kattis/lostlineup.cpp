#include <bits/stdc++.h>
using namespace std;

// Lost Lineup

int n, x, b[103];

int main(){
    cin >> n, b[0] = 1;
    for(int i = 0; i < n-1; i++)
        cin >> x, b[x+1] = i + 2;
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}