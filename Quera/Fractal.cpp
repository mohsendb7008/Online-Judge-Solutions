#include <bits/stdc++.h>
using namespace std;

int n, k, p[6];
char pat[3][3], ans[243][243];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> pat[i][j];
    p[0] = 1;
    for(int i = 1; i <= k; i++)
        p[i] = p[i-1] * n;
    for(int i = 0; i < p[k]; i++)
        for(int j = 0; j < p[k]; j++){
            int x = i, y = j, z = k-1;
            while(1){
                if(!z){
                    ans[i][j] = pat[x][y];
                    break;
                }
                if(pat[x / p[z]][y / p[z]] == '*'){
                    ans[i][j] = '*';
                    break;
                }
                x %= p[z], y %= p[z], z--;
            }
        }
    for(int i = 0; i < p[k]; i++){
        for(int j = 0; j < p[k]; j++)
            cout << ans[i][j];
        cout << endl;
    }
}