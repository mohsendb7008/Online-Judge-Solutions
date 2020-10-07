#include <bits/stdc++.h>
using namespace std;

// Bit Maps

int cnt = 0;

inline void prc(char c){
    if(cnt == 50){
        cout << endl;
        cnt = 0;
    }
    cout << c;
    cnt++;
}

int n, m;
char mat[203][203];
int psum[203][203];

inline int get(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m)
        return psum[x][y];
    return 0;
}

void print(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2){
        prc(mat[x1][y1]);
        return;
    }
    int sum = psum[x2][y2] - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
    if(sum == 0){
        prc('0');
        return;
    }
    if(sum == (x2-x1+1) * (y2-y1+1)){
        prc('1');
        return;
    }
    prc('D');
    if(x1 == x2){
        int mid = (y1 + y2) / 2;
        print(x1, y1, x2, mid);
        print(x1, mid+1, x2, y2);
        return;
    }
    if(y1 == y2){
        int mid = (x1 + x2) / 2;
        print(x1, y1, mid, y2);
        print(mid+1, y1, x2, y2);
        return;
    }
    int midx = (x1 + x2) / 2;
    int midy = (y1 + y2) / 2;
    print(x1, y1, midx, midy);
    print(x1, midy+1, midx, y2);
    print(midx+1, y1, x2, midy);
    print(midx+1, midy+1, x2, y2);
}

void build(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2){
        cin >> mat[x1][y1];
        return;
    }
    char c;
    cin >> c;
    if(c != 'D'){
        for(int x = x1; x <= x2; x++)
            for(int y = y1; y <= y2; y++)
                mat[x][y] = c;
        return;
    }
    if(x1 == x2){
        int mid = (y1 + y2) / 2;
        build(x1, y1, x2, mid);
        build(x1, mid+1, x2, y2);
        return;
    }
    if(y1 == y2){
        int mid = (x1 + x2) / 2;
        build(x1, y1, mid, y2);
        build(mid+1, y1, x2, y2);
        return;
    }
    int midx = (x1 + x2) / 2;
    int midy = (y1 + y2) / 2;
    build(x1, y1, midx, midy);
    build(x1, midy+1, midx, y2);
    build(midx+1, y1, x2, midy);
    build(midx+1, midy+1, x2, y2);
    return;
}

int main(){
    char c;
    while(183){
        cin >> c;
        if(c == '#')
            break;
        else if(c == 'B'){
            cin >> n >> m;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    cin >> mat[i][j], psum[i][j] = mat[i][j] - '0' + get(i-1, j) + get(i, j-1) - get(i-1, j-1);
            cout << 'D' << right << setw(4) << n << right << setw(4) << m << endl;
            cnt = 0;
            print(0, 0, n-1, m-1);
            cout << endl;
        }
        else if(c == 'D'){
            cin >> n >> m;
            build(0, 0, n-1, m-1);
            cout << 'B' << right << setw(4) << n << right << setw(4) << m << endl;
            cnt = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    prc(mat[i][j]);
            cout << endl;
        }
    }
}