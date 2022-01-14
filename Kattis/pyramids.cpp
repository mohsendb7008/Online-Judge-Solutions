// Building Pyramids

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, acc = 0, i = 1;
    cin >> n;
    for(; acc <= n; i += 2)
        acc += i * i;
    cout << i / 2 - 1 << endl;
}