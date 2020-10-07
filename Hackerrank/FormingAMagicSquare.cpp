#include <bits/stdc++.h>
using namespace std;

int g[3][3], t[3][3], ans = INT_MAX;

void track(int i){
     if(i == 5){
         int val = t[0][0] + t[0][1] + t[0][2];
         t[1][2] = val - t[1][0] - t[1][1];
         t[2][0] = val - t[1][0] - t[0][0];
         t[2][1] = val - t[1][1] - t[0][1];
         t[2][2] = val - t[1][2] - t[0][2];
         for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(t[i][j] < 1 || t[i][j] > 9)
                    return;
        for(int i = 0; i < 3; i++)
            if(t[i][0] + t[i][1] + t[i][2] != val)
                return;
        for(int j = 0; j < 3; j++)
            if(t[0][j] + t[1][j] + t[2][j] != val)
                return;
        if(t[0][0] + t[1][1] + t[2][2] != val)
            return;
        if(t[0][2] + t[1][1] + t[2][0] != val)
            return;
        set<int> s;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                s.insert(t[i][j]);
        if(s.size() < 9)
            return;
        int cost = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cost += abs(t[i][j] - g[i][j]);
        ans = min(ans, cost);
        return;
     }
     for(int n = 1; n <= 9; n++)
        t[i/3][i%3] = n, track(i+1);
}

int main(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> g[i][j];
    track(0);
    cout << ans << endl;
}