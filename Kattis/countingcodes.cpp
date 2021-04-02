#include <bits/stdc++.h>
using namespace std;

// Counting Codes

int n, m, grid[6][6];
set<int> domain[6][6], all{1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<pair<int, int>> priority;
long long int ans = 0;

inline bool check_it(int u, int l, int r){
    return u == l * r || u == l + r || u == abs(l - r) || (l % r == 0 && u == l / r) || (r % l == 0 && u == r / l);
}

inline bool feasible_numbering(int row, int column, int value){
    if(row - 1 >= 0 && column + 1 < m && grid[row - 1][column] && grid[row][column + 1] && !check_it(value, grid[row - 1][column], grid[row][column + 1]))
        return false;
    if(row - 1 >= 0 && column - 1 >= 0 && grid[row][column - 1] && grid[row - 1][column - 1] && !check_it(grid[row][column - 1], grid[row - 1][column - 1], value))
        return false;
    if(row + 1 < n && column + 1 < m && grid[row + 1][column] && grid[row + 1][column + 1] && !check_it(grid[row + 1][column], value, grid[row + 1][column + 1]))
        return false;
    return true;
}

inline bool forward_checking(int row, int column, int value, vector<pair<int, int>>& omits){
    for(int j = 0; j < m; j++){
        if(j == column || grid[row][j])
            continue;
        if(domain[row][j].find(value) != domain[row][j].end()){
            if(domain[row][j].size() == 1)
                return false;
            omits.push_back({row, j});
        }
    }
    return true;
}

void backtracking_search(int assigned_count){
    if(assigned_count == n * m){
        ans++;
        return;
    }
    int i = priority[assigned_count].first, j = priority[assigned_count].second;
    for(int candidate_number : domain[i][j]){
        if(!feasible_numbering(i, j, candidate_number))
            continue;
        vector<pair<int, int>> omits;
        if(!forward_checking(i, j, candidate_number, omits))
            continue;
        grid[i][j] = candidate_number;
        for(auto omit : omits)
            domain[omit.first][omit.second].erase(candidate_number);
        backtracking_search(assigned_count + 1);
        for(auto omit : omits)
            domain[omit.first][omit.second].insert(candidate_number);
        grid[i][j] = 0;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x)
                domain[i][j].insert(x), priority.push_back({i, j});
            else
                domain[i][j] = all;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(domain[i][j].size() > 1)
                priority.push_back({i, j});
    backtracking_search(0);
    cout << ans << endl;
}