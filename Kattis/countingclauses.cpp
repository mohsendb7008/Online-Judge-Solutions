#include <bits/stdc++.h>
using namespace std;

// Counting Clauses

int m, n, a[23][3];

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];
    if(m < 8){
        cout << "unsatisfactory" << endl;
        return 0;
    }
    cout << "satisfactory" << endl;
}