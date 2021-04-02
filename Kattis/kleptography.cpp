#include <bits/stdc++.h>
using namespace std;

// Kleptography

int n, m;
char a[103], b[103];

int main(){
    cin >> n >> m >> a + m - n >> b;
    for(int i = m - n - 1; i >= 0; i--)
        a[i] = (b[i + n] - a[i + n] + 26) % 26 + 'a'; 
    cout << a << endl;
}