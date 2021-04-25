#include <bits/stdc++.h>
using namespace std;

// Weak Vertices

int n, g[23][23];

int main(){
    while(1){
        cin >> n;
        if(n == -1)
            break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> g[i][j];
        vector<int> weak;
        for(int i = 0; i < n; i++){
            bool isweak = 1;
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(i != j && i != k && j != k && g[i][j] && g[i][k] && g[j][k])
                        isweak = 0;
            if(isweak)
                weak.push_back(i);
        }
        for(int i : weak)
            cout << i << ' ';
        cout << '\n';
    }
}