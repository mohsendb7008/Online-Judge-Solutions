#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, q;
num arr[503][503], ps[503][503];

inline num get(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < n)
        return ps[i][j];
    return 0;
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ps[i][j] = arr[i][j] + get(i-1, j) + get(i, j-1) - get(i-1, j-1);
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ps[x2][y2] - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1) << endl;
    }
}