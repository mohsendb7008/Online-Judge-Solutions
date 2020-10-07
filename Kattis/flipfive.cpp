#include <bits/stdc++.h>
using namespace std;

// Flip Five

char g[3][3], tmp[3][3];
map<string, int> dis;

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

int main(){
    string src = "";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            src += '.';
    queue<string> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()){
        string x = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                g[i][j] = x[i * 3 + j];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                tmp[i][j] = g[i][j];
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                tmp[i][j] = (tmp[i][j] == '.') ? '*' : '.';
                for(int k = 0; k < 4; k++){
                    int ni = i + adjR[k], nj = j + adjC[k];
                    if(ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                        tmp[ni][nj] = (tmp[ni][nj] == '.') ? '*' : '.';
                }
                string y = "";
                for(int ii = 0; ii < 3; ii++)
                    for(int jj = 0; jj < 3; jj++)
                        y += tmp[ii][jj];
                if(dis.find(y) == dis.end()){
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        tmp[i][j] = g[i][j];
            }
    }    
    int t;
    cin >> t;
    while(t--){
        string dst = "";
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                char c;
                cin >> c;
                dst += c;
            }
        cout << dis[dst] << endl;
    }
}