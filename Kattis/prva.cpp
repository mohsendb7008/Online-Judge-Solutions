#include <bits/stdc++.h>
using namespace std;

// Prva

int n, m;
char g[23][23];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    string ans = "\xff";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] == '#')
                continue;
            if(!j || g[i][j-1] == '#'){
                string curr = "";
                int ptr = j;
                while(ptr < m){
                    if(g[i][ptr] == '#')
                        break;
                    curr.push_back(g[i][ptr++]);
                }
                if(curr.size() > 1)
                    ans = min(ans, curr);
            }
            if(!i || g[i-1][j] == '#'){
                string curr = "";
                int ptr = i;
                while(ptr < n){
                    if(g[ptr][j] == '#')
                        break;
                    curr.push_back(g[ptr++][j]);
                }
                if(curr.size() > 1)
                    ans = min(ans, curr);
            }
        }
    cout << ans << endl;
}