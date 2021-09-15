#include <bits/stdc++.h>
using namespace std;

char g[3][3];

inline int cnt(char c){
    int ans = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(g[i][j] == c)
                ans++;
    return ans;
}

inline bool win(char c){
    if(g[0][0] == c && g[0][1] == c && g[0][2] == c)
        return 1;
    if(g[1][0] == c && g[1][1] == c && g[1][2] == c)
        return 1;
    if(g[2][0] == c && g[2][1] == c && g[2][2] == c)
        return 1;
    if(g[0][0] == c && g[1][0] == c && g[2][0] == c)
        return 1;
    if(g[0][1] == c && g[1][1] == c && g[2][1] == c)
        return 1;
    if(g[0][2] == c && g[1][2] == c && g[2][2] == c)
        return 1;
    if(g[0][0] == c && g[1][1] == c && g[2][2] == c)
        return 1;
    if(g[0][2] == c && g[1][1] == c && g[2][0] == c)
        return 1;
    return 0;
}

int main(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> g[i][j];
    int x = cnt('X'), o = cnt('0');
    if(!(x == o + 1) && !(x == o))
        cout << "illegal" << endl;
    else if(win('X') && win('0'))
        cout << "illegal" << endl;
    else if(win('X'))
        cout << (x == o + 1 ? "the first player won" : "illegal") << endl;
    else if(win('0'))
        cout << (x == o ? "the second player won" : "illegal") << endl;
    else if(x == 5)
        cout << "draw" << endl;
    else if(x == o)
        cout << "first" << endl;
    else
        cout << "second" << endl;
}