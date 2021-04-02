#include <bits/stdc++.h>
using namespace std;

// Peg Game for Two

#define num long long int

map<pair<string, bool>, num> memo;
int adjR[6]{-1, 1, 0, 0, -1, 1};
int adjC[6]{0, 0, -1, 1, -1, 1};

num dp(string state, bool turn){
    pair<string, bool> p = {state, turn};
    if(memo.find(p) != memo.end())
        return memo[p];
    num ans = turn ? INT_MIN : INT_MAX;
    int game[5][5];
    stringstream ss(state);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < i + 1; j++)
            ss >> game[i][j];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < i + 1; j++)
            if(game[i][j])
                for(int k = 0; k < 6; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    int xx = i + 2 * adjR[k], yy = j + 2 * adjC[k];
                    if(x >= 0 && x < 5 && y >= 0 && y < x + 1 && xx >= 0 && xx < 5 && yy >= 0 && yy < xx + 1 && game[x][y] && !game[xx][yy]){
                        string subp = "";
                        for(int ii = 0; ii < 5; ii++)
                            for(int jj = 0; jj < ii + 1; jj++){
                                if(ii == i && jj == j)
                                    subp += "0 ";
                                else if(ii == x && jj == y)
                                    subp += "0 ";
                                else if(ii == xx && jj == yy)
                                    subp += to_string(game[i][j]) + " ";
                                else 
                                    subp += to_string(game[ii][jj]) + " ";
                            }
                        if(turn)
                            ans = max(ans, game[i][j] * game[x][y] + dp(subp, !turn));
                        else 
                            ans = min(ans, - game[i][j] * game[x][y] + dp(subp, !turn));
                    }
                }
    return memo[p] = (ans == INT_MIN || ans == INT_MAX) ? 0 : ans;
}

int main(){
    string s = "";
    int x;
    for(int i = 0; i < 15; i++)
        cin >> x, s += to_string(x) + " ";
    cout << dp(s, true) << endl;
}