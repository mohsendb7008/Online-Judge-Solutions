#include <bits/stdc++.h>
using namespace std;

// Polynomial Multiplication 1

int t, n, m, a[258], b[258], c[513];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i <= n; i++)
            cin >> a[i];
        cin >> m;
        for(int i = 0; i <= m; i++)
            cin >> b[i];
        fill_n(c, n + m + 1, 0);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                c[i + j] += a[i] * b[j];
        cout << n + m << endl;
        for(int i = 0; i <= n + m; i++)
            cout << c[i] << " ";
        cout << endl;
    }
}