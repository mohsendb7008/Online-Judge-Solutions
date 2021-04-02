#include <bits/stdc++.h>
using namespace std;

// K-In-A-Row

int l, n, m, k, x = 0, o = 0;
char g[203][203];

int adjR[4]{1, 0, 1, 1};
int adjC[4]{0, 1, 1, -1};

bool test(int i, int j, char c){
    for(int z = 0; z < 4; z++){
        bool ok = 1;
        for(int e = 0; e < k; e++){
            int x = i + e * adjR[z], y = j + e * adjC[z];
            if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] != c){
                ok = 0;
                break;
            }
        }
        if(ok)
            return true;
    }
    return false;
}

int main(){
    cin >> l;
    while(l--){
        cin >> m >> n >> k;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        bool found = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(test(i, j, 'o')){
                    o++;
                    found = 1;
                    break;
                }
                if(test(i, j, 'x')){
                    x++;
                    found = 1;
                    break;
                }
            }
            if(found)
                break;
        }
    }
    cout << x << ":" << o << endl;
}