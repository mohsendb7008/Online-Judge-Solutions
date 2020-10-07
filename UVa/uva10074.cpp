#include <bits/stdc++.h>
using namespace std;

// Take the Land

int n, m;
int psum[103][103];

int get(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m)
        return psum[i][j];
    return 0;
}

int main(){
    while(1){
        cin >> n >> m;
        if(n + m == 0)
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> psum[i][j];
                psum[i][j] += get(i-1, j) + get(i, j-1) - get(i-1, j-1);
            }
        int max_area = 0;
        for(int x1 = 0; x1 < n; x1++)
            for(int y1 = 0; y1 < m; y1++)
                for(int x2 = x1; x2 < n; x2++)
                    for(int y2 = y1; y2 < m; y2++){
                        int value = psum[x2][y2] - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
                        if(value == 0){
                            int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                            max_area = max(max_area, area);
                        }
                    }
        cout << max_area << endl;
    }
}