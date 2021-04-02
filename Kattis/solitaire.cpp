#include <bits/stdc++.h>
using namespace std;

// Peg Solitaire

map<vector<string>, pair<int, int>> memo;

inline void relax(pair<int, int>& ans, pair<int, int> subp){
    if(subp.first < ans.first){
        ans.first = subp.first;
        ans.second = subp.second + 1;
    }
    else if(subp.first == ans.first)
        ans.second = min(ans.second, subp.second + 1);
}

pair<int, int> cdp(vector<string> game){
    if(memo.find(game) != memo.end())
        return memo[game];
    pair<int, int> ans = {0, 0};
    for(string row: game)
        ans.first += count(row.begin(), row.end(), 'o');
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 7; j++){
            if(game[i].substr(j, 3) == "oo."){
                vector<string> clone = game;
                clone[i][j] = '.';
                clone[i][j+1] = '.';
                clone[i][j+2] = 'o';
                relax(ans, cdp(clone));
            }
            else if(game[i].substr(j, 3) == ".oo"){
                vector<string> clone = game;
                clone[i][j] = 'o';
                clone[i][j+1] = '.';
                clone[i][j+2] = '.';
                relax(ans, cdp(clone));
            }
        }
    for(int j = 0; j < 9; j++)
        for(int i = 0; i < 3; i++){
            if(game[i][j] == 'o' && game[i+1][j] == 'o' && game[i+2][j] == '.'){
                vector<string> clone = game;
                clone[i][j] = '.';
                clone[i+1][j] = '.';
                clone[i+2][j] = 'o';
                relax(ans, cdp(clone));
            }
            else if(game[i][j] == '.' && game[i+1][j] == 'o' && game[i+2][j] == 'o'){
                vector<string> clone = game;
                clone[i][j] = 'o';
                clone[i+1][j] = '.';
                clone[i+2][j] = '.';
                relax(ans, cdp(clone));
            }
        }
    return memo[game] = ans;
}

int main(){
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    while(t--){
        vector<string> game(5);
        for(int i = 0; i < 5; i++)
            getline(cin, game[i]);
        getline(cin, str);
        memo.clear();
        pair<int, int> ans = cdp(game); 
        cout << ans.first << " " << ans.second << endl;
    }
}