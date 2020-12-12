#include <bits/stdc++.h>
using namespace std;

// Crashing Robots

int adjR[4]{1, 0, -1, 0};
int adjC[4]{0, 1, 0, -1};
map<char, int> dm{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
int n, m, r, rx[103], ry[103], rd[103], g[103][103], c; 

int main(){
    int k, a, d, x, y;
    char t;
    cin >> k;
    while(k--){
        cin >> m >> n >> r >> c;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                g[i][j] = -1;
        for(int i = 0; i < r; i++)
            cin >> ry[i] >> rx[i] >> t, ry[i]--, rx[i]--, g[rx[i]][ry[i]] = i, rd[i] = dm[t];
        bool ok = true;
        while(c--){
            cin >> a >> t >> d, a--;
            if(!ok)
                continue;
            if(t == 'R')
                rd[a] = (rd[a] + d) % 4;
            else if(t == 'L')
                rd[a] = (rd[a] - d + 400) % 4;
            else{
                while(d--){
                    x = rx[a] + adjR[rd[a]], y = ry[a] + adjC[rd[a]];
                    if(!(x >= 0 && x < n && y >= 0 && y < m)){
                        cout << "Robot " << a + 1 << " crashes into the wall" << endl;
                        ok = false;
                        break;
                    }
                    else if(g[x][y] != -1){
                        cout << "Robot " << a + 1 << " crashes into robot " << g[x][y] + 1 << endl;
                        ok = false;
                        break;
                    }
                    else
                        g[rx[a]][ry[a]] = -1, g[x][y] = a, rx[a] = x, ry[a] = y;
                }
            }
        }
        if(ok)
            cout << "OK" << endl;
    }
}