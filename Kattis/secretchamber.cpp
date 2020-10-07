#include <bits/stdc++.h>
using namespace std;

// Secret Chamber at Mount Rushmore

bool floyd[29][29];
int n, m;
char x, y;
string u, v;

int main(){
    for(int i = 0; i < 26; i++)
        floyd[i][i] = true;
    cin >> n >> m;
    while(n--)
        cin >> x >> y, floyd[x-'a'][y-'a'] = true;
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                if(floyd[i][k] && floyd[k][j])
                    floyd[i][j] = true;
    while(m--){
        cin >> u >> v;
        if(u.size() != v.size()){
            cout << "no" << endl;
            continue;
        }
        bool ok = true;
        for(int i = 0; i < u.size(); i++)
            if(!floyd[u[i]-'a'][v[i]-'a']){
                ok = false;
                break;
            }
        cout << (ok ? "yes" : "no") << endl;
    }
}