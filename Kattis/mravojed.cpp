#include <bits/stdc++.h>
using namespace std;

// Mravojed

int n, m, g[103][103], x = 0, ax = -1, ay, psum[103][103];

inline int get(int i, int j){
    if(i >= 0 && j >= 0)
        return psum[i][j];
    return 0;
}

inline int rect(int x1, int y1, int x2, int y2){
    return psum[x2][y2] - get(x2, y1-1) - get(x1-1, y2) + get(x1-1, y1-1);
}

inline int uni(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int cx1 = max(ax1, bx1), cx2 = min(ax2, bx2);
    if(cx1 > cx2)
        return 0;
    int cy1 = max(ay1, by1), cy2 = min(ay2, by2);
    if(cy1 > cy2)
        return 0;
    return rect(cx1, cy1, cx2, cy2);
}

int main(){
    char c;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == 'x'){
                g[i][j] = 1;
                x++;
                if(ax == -1)
                    ax = i, ay = j;
            }
            psum[i][j] = g[i][j] + get(i-1, j) + get(i, j-1) - get(i-1, j-1);
        }
    for(int l1 = 0; ax + l1 < n && ay + l1 < m; l1++)
        if(rect(ax, ay, ax + l1, ay + l1) == (l1 + 1) * (l1 + 1))
            for(int bx = 0; bx < n; bx++)
                for(int by = 0; by < m; by++)
                    if(g[bx][by] == 1)
                        for(int l2 = 0; bx + l2 < n && by + l2 < m; l2++)
                            if(rect(bx, by, bx + l2, by + l2) == (l2 + 1) * (l2 + 1))
                                if(rect(ax, ay, ax + l1, ay + l1) + rect(bx, by, bx + l2, by + l2)
                                   - uni(ax, ay, ax + l1, ay + l1, bx, by, bx + l2, by + l2) == x){
                                       cout << ax + 1 << " " << ay + 1 << " " << l1 + 1 << endl;
                                       cout << bx + 1 << " " << by + 1 << " " << l2 + 1 << endl;
                                       return 0;
                                   }
}