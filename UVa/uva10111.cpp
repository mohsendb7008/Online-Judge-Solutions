#include <bits/stdc++.h>
using namespace std;

// Find the Winning Move

#define N true
#define P false

map<pair<string, bool>, bool> memo;
map<pair<string, bool>, int> trace;

bool dp(string state, bool turn){
    pair<string, bool> p = {state, turn};
    if(memo.find(p) != memo.end())
        return memo[p];
    char g[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            g[i][j] = state[i * 4 + j];
    for(int i = 0; i < 4; i++)
        if(g[i][0] != '.' && g[i][0] == g[i][1] && g[i][1] == g[i][2] && g[i][2] == g[i][3])
            return memo[p] = P;
    for(int j = 0; j < 4; j++)
        if(g[0][j] != '.' && g[0][j] == g[1][j] && g[1][j] == g[2][j] && g[2][j] == g[3][j])
            return memo[p] = P;
    if(g[0][0] != '.' && g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[2][2] == g[3][3])
        return memo[p] = P;
    if(g[0][3] != '.' && g[0][3] == g[1][2] && g[1][2] == g[2][1] && g[2][1] == g[3][0])
        return memo[p] = P;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            if(g[i][j] == '.'){
                string subp = "";
                for(int x = 0; x < 4; x++)
                    for(int y = 0; y < 4; y++)
                        subp += (x == i && y == j) ? (turn ? 'x' : 'o') : g[x][y];
                if(dp(subp, !turn) == P){
                    trace[p] = 4 * i + j;
                    return memo[p] = N;
                }
            }
    }
    return memo[p] = P;
}

int main(){
    char t;
    while(1){
        cin >> t;
        if(t == '$')
            break;
        string state = "";
        for(int i = 0; i < 16; i++)
            cin >> t, state += t;
        if(dp(state, true) == N){
            int ans = trace[{state, true}];
            cout << '(' << ans / 4 << ',' << ans % 4 << ')' << endl;
        }
        else cout << "#####" << endl;
    }
}