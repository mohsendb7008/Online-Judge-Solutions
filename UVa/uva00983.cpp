#include <bits/stdc++.h>
using namespace std;

// Localized Summing for Blurring

int n, m;
#define num long long int

num psum[1003][1003];

num get(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < n)
        return psum[i][j];
    return 0;
}

num rect(int x1, int y1, int x2, int y2){
    return get(x2, y2) - get(x2, y1-1) - get(x1-1, y2) + get(x1-1, y1-1);
}

int main(){
    bool first = true;
    while(cin >> n >> m){
        if(!first)
            cout << endl;
        first = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> psum[i][j];
                psum[i][j] += get(i-1, j) + get(i, j-1) - get(i-1, j-1);
            }
        num ans = 0;
        for(int i = 0; i < n - m + 1; i++)
            for(int j = 0; j < n - m + 1; j++){
                int r = rect(i, j, i + m - 1, j + m - 1);
                cout << r << endl;
                ans += r;
            }
        cout << ans << endl;
    }
}