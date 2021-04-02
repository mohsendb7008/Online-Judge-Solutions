#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m, k;
num arr[53][53], ps[53][53];

inline num get(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m)
        return ps[i][j];
    return 0;
}

inline num rect(int x1, int y1, int x2, int y2){
    return ps[x2][y2] - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}

int main(){
    cin >> n >> m >> k;
    int zero = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j], zero += 1 - arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ps[i][j] = arr[i][j] + get(i-1, j) + get(i, j-1) - get(i-1, j-1);
    int ans = 0;
    for(int x1 = 0; x1 + k - 1 < n; x1++)
        for(int y1 = 0; y1 + k - 1 < m; y1++)
            for(int x2 = 0; x2 + k - 1 < n; x2++)
                for(int y2 = 0; y2 + k - 1 < m; y2++){
                    int cur = rect(x1, y1, x1 + k - 1, y1 + k - 1) + rect(x2, y2, x2 + k - 1, y2 + k - 1);
                    int x3 = max(x1, x2), x4 = min(x1 + k - 1, x2 + k - 1);
                    int y3 = max(y1, y2), y4 = min(y1 + k - 1, y2 + k - 1);
                    if(x3 <= x4 && y3 <= y4)
                        cur -= rect(x3, y3, x4, y4);
                    ans = max(ans, cur);
                }
    cout << zero + ans << endl;
}