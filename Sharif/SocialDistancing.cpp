#include <bits/stdc++.h>
using namespace std;

const int maxnm = 500;
const int inf = INT_MAX;

int n, m, nearest_patient[maxnm][maxnm], vis[maxnm][maxnm];
char grid[maxnm][maxnm];
pair<int, int> source, destination;
vector<int> patients_by_row[maxnm];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

queue<pair<int, int>> bfs;

bool judge(int social_distance){
    if(nearest_patient[source.first][source.second] < social_distance)
        return false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = false;
    vis[source.first][source.second] = true;
    bfs.push(source);
    while(!bfs.empty()){
        int ux = bfs.front().first, uy = bfs.front().second;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int vx = ux + adjR[k], vy = uy + adjC[k];
            if(vx >= 0 && vx < n && vy >= 0 && vy < m && grid[vx][vy] != '#' && grid[vx][vy] != '*' && nearest_patient[vx][vy] >= social_distance && !vis[vx][vy])
                vis[vx][vy] = true, bfs.push({vx, vy}); 
        }
    }
    return vis[destination.first][destination.second];
}

int main(){
    cin >> n >> m;
    bool having_patient = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            nearest_patient[i][j] = inf;
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
                source = {i, j};
            else if(grid[i][j] == 'E')
                destination = {i, j};
            else if(grid[i][j] == '*')
                patients_by_row[i].push_back(j), having_patient = true;
        }
    if(!judge(0)){
        cout << -1 << endl;
        return 0;
    }
    if(!having_patient){
        cout << "safe" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int row = 0; row < n; row++){
                if(patients_by_row[row].empty())
                    continue;
                int patient_distance = abs(i - row);
                if(nearest_patient[i][j] <= patient_distance)
                    continue;
                auto column = upper_bound(patients_by_row[row].begin(), patients_by_row[row].end(), j);
                int column_distance = inf;
                if(column != patients_by_row[row].end())
                    column_distance = min(column_distance, abs(j - *column));
                if(column != patients_by_row[row].begin())
                    column_distance = min(column_distance, abs(j - *prev(column)));
                patient_distance = max(patient_distance, column_distance);
                nearest_patient[i][j] = min(nearest_patient[i][j], patient_distance);
            }
    int lo = 1, hi = maxnm;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
}