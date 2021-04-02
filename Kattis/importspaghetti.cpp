#include <bits/stdc++.h>
using namespace std;

// Import Spaghetti

#define inf INT_MAX

int n;
string names[503];
map<string, int> id;
int floyd[503][503];
int par[503][503];

void path(int i, int j){
    int k = par[i][j];
    if(k == -1)
        cout << names[i] << " ";
    else{
        path(i, k);
        path(k, j);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> names[i], id[names[i]] = i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            floyd[i][j] = inf, par[i][j] = -1;
    string x;
    int m;
    for(int i = 0; i < n; i++){
        cin >> x >> m;
        cin.ignore();
        for(int j = 0; j < m; j++){
            getline(cin, x);
            x = x.substr(6, x.size() - 6);
            stringstream ss(x);
            string y;
            while(getline(ss, y, ',')){
                int k = id[y.substr(1, y.size() - 1)];
                floyd[i][k] = 1;
            }
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(floyd[i][k] != inf && floyd[k][j] != inf && floyd[i][k] + floyd[k][j] < floyd[i][j])
                    floyd[i][j] = floyd[i][k] + floyd[k][j], par[i][j] = k;
    int ans = inf;
    for(int i = 0; i < n; i++)
        ans = min(ans, floyd[i][i]);
    if(ans == inf){
        cout << "SHIP IT" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(floyd[i][i] == ans){ 
            path(i, i);
            return 0;
        }
}