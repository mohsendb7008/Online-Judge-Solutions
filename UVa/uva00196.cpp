#include <bits/stdc++.h>
using namespace std;

// Spreadsheet

vector<string> split(const string& str, char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

int n, m;
string grid[1002][18281];

string visit(int i, int j){
    if(grid[i][j][0] != '=')
        return grid[i][j];
    long long int ans = 0;
    vector<string> cells = split(grid[i][j].substr(1), '+');
    for(string cell: cells){
        int row;
        char column[4];
        sscanf(cell.c_str(), "%[A-Z]%d", column, &row);
        int clen = strlen(column);
        int col = 0;
        int exp = 1;
        for(int i = clen-1; i >= 0; i--){
            col += (column[i] - 'A' + 1) * exp;
            exp *= 26;
        }
        ans += stoll(visit(row-1, col-1));
    }
    char result[20];
    sprintf(result, "%lld", ans);
    return grid[i][j] = string(result);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << visit(i, j) << (j == m -1 ? "" : " ");
            cout << endl;
        }
    }
}