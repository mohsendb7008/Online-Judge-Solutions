#include <bits/stdc++.h>
using namespace std;

// Tomography

int n, m, row[1003], col[1003], rsum = 0, csum = 0;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> row[i], rsum += row[i];
    for(int i = 0; i < m; i++)
        cin >> col[i], csum += col[i];
    if(rsum != csum){
        cout << "No" << endl;
        return 0;
    }
    sort(row, row + n, greater<int>());
    for(int i = 0; i < n; i++){
        sort(col, col + m, greater<int>());
        for(int j = 0; j < m; j++){
            if(!row[i])
                break;
            if(col[j])
                row[i]--, col[j]--;
        }
        if(row[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}