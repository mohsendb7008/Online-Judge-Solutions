#include <bits/stdc++.h>
using namespace std;

// Froggie

int l, w, O[13], I[13], S[13], W[13], x, y;
char g[13][123], tmp[123];
string cmd;
int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};
map<char, int> dir{
    {'L', 0},
    {'R', 1},
    {'U', 2},
    {'D', 3},
};

int main(){
    cin >> l >> w;
    for(int i = 1; i <= l; i++){
        cin >> O[i] >> I[i] >> S[i], W[i] = w;
        if(w % I[i])
            W[i] += I[i] - w % I[i];
        if(!(i % 2))
            O[i] = w-1-O[i];
        for(int j = 0; j < W[i]; j++)
            g[i][j] = '.';
        int j = O[i];
        g[i][j] = 'C', j = (j + I[i]) % W[i];
        while(j != O[i])
            g[i][j] = 'C', j = (j + I[i]) % W[i];
    }
    x = l+1, cin >> y >> cmd;
    for(char c : cmd){
        x += adjR[dir[c]], y += adjC[dir[c]];
        if(!x){
            cout << "safe" << endl;
            return 0;
        }
        for(int i = 1; i <= l; i++){
            int k = i % 2 ? 1 : -1;
            for(int j = 0; j < W[i]; j++)
                tmp[j] = '.';
            for(int j = 0; j < W[i]; j++)
                if(g[i][j] == 'C'){
                    if(!S[i] && x == i && y == j){
                        cout << "squish" << endl;
                        return 0;
                    }
                    int r = S[i], z = j;
                    while(r--){
                        z = (z + k + W[i]) % W[i];
                        if(x == i && y == z){
                            cout << "squish" << endl;
                            return 0;
                        }
                    }
                    tmp[z] = 'C';
                }
            for(int j = 0; j < W[i]; j++)
                g[i][j] = tmp[j];
        }
    }
    if(x)
        cout << "squish" << endl;
    else
        cout << "safe" << endl;
}