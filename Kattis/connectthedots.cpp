#include <bits/stdc++.h>
using namespace std;

// Connect the Dots

int n, m;
vector<string> lines;

void connect(int x1, int y1, int x2, int y2){
    if(x1 == x2)
        for(int k = min(y1, y2) + 1; k <= max(y1, y2) - 1; k++){
            if(lines[x1][k] == '.')
                lines[x1][k] = '-';
            else if(lines[x1][k] == '|')
                lines[x1][k] = '+';
        }
    else if(y1 == y2)
        for(int k = min(x1, x2) + 1; k <= max(x1, x2) - 1; k++){
            if(lines[k][y1] == '.')
                lines[k][y1] = '|';
            else if(lines[k][y1] == '-')
                lines[k][y1] = '+';
        }
}

string a = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int> ord;
map<char, pair<int, int>> pos;

void solve(){
    n = lines.size(), m = lines[0].size();
    int c = -1;
    pos.clear();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(lines[i][j] != '.')
                c = max(c, ord[lines[i][j]]), pos[lines[i][j]] = {i, j};
    if(c >= 1)
        for(int i = 0; i < c; i++){
            pair<int, int> p1 = pos[a[i]];
            pair<int, int> p2 = pos[a[i+1]];
            connect(p1.first, p1.second, p2.first, p2.second);
        }
    for(string line : lines)
        cout << line << endl;
}

int main(){
    for(int i = 0; i < a.size(); i++)
        ord[a[i]] = i;
    string line;
    while(getline(cin, line)){
        if(line.empty()){
            solve();
            cout << endl;        
            lines.clear();
        }
        else lines.push_back(line);
    }
    if(!lines.empty())
        solve();
}