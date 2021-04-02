#include <bits/stdc++.h>
using namespace std;

// Exam

string a, b;

int main(){
    int c;
    cin >> c >> a >> b;
    int m = 0, n = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i])
            m++;
        else n++;
    }
    if(c <= m)
        cout << c + n << endl;
    else
        cout << 2 * m + n - c << endl;
}