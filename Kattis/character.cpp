#include <bits/stdc++.h>
using namespace std;

// Character Development

int main(){
    int n;
    cin >> n;
    if(n <= 1)
        cout << 0 << endl;
    else
        cout << (1 << n) - n - 1 << endl;
}