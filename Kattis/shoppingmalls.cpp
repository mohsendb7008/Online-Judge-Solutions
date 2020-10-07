#include <bits/stdc++.h>
using namespace std;

// Shopping Malls

int n, m;
struct point{
    int x, y, z;
} points[203];

inline double dis(int i, int j){
    double dx = points[i].x - points[j].x, dy = points[i].y - points[j].y, dz = points[i].z - points[j].z;
    return sqrt(dx * dx + dy * dy + dz * dz * 25.0);
}

const double inf = LLONG_MAX;

double floyd[203][203];
int par[203][203];

void path(int i, int j){
    int k = par[i][j];
    if(k == -1)
        cout << j << " ";
    else{
        path(i, k);
        path(k, j);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> points[i].z >> points[i].x >> points[i].y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            floyd[i][j] = i == j ? 0 : inf, par[i][j] = -1;
    int x, y;
    string s;
    while(m--){
        cin >> x >> y >> s;
        double d = dis(x, y);
        if(s == "walking" || s == "stairs"){
            floyd[x][y] = min(floyd[x][y], d);
            floyd[y][x] = min(floyd[y][x], d);
        }
        else if(s == "lift"){
            floyd[x][y] = min(floyd[x][y], 1.0);
            floyd[y][x] = min(floyd[y][x], 1.0);
        }
        else{
            floyd[x][y] = min(floyd[x][y], 1.0);
            floyd[y][x] = min(floyd[y][x], 3 * d);
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][k] + floyd[k][j] < floyd[i][j])
                    floyd[i][j] = floyd[i][k] + floyd[k][j], par[i][j] = k;
    cin >> m;
    while(m--){
        cin >> x >> y;
        cout << x << " ";
        path(x, y);
        cout << endl;
    }
}