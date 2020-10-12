#include <bits/stdc++.h>
using namespace std;

// Indoorienteering

#define num long long int

int n;
num l, g[14 + 3][14 + 3];

int m, tsp[14 + 3];
bool taken[14 + 3];
int mask = 0;
num aug = 0;
unordered_set<num> halfc[(1 << 14) + 3][14 + 3];

void track1(int i){
    for(int cand = 1; cand < n; cand++)
        if(!taken[cand]){
            tsp[i] = cand;
            taken[cand] = 1;
            mask += 1 << cand;
            if(i)
                aug += g[tsp[i-1]][cand];
            if(i == m-1)
                halfc[mask][tsp[0]].insert(aug + g[cand][0]);
            else 
                track1(i + 1);
            if(i)
                aug -= g[tsp[i-1]][cand];
            mask -= 1 << cand;
            taken[cand] = 0;
        }
}

bool ans = false;

void track2(int i){
    if(ans)
        return;
    for(int cand = 1; cand < n; cand++)
        if(!taken[cand]){
            tsp[i] = cand;
            taken[cand] = 1;
            mask += 1 << cand;
            aug += g[tsp[i-1]][cand];
            if(i == m-1){
                int residual = (1 << n) - 1 - mask;
                for(int k = 0; k < n; k++)
                    if((residual & (1 << k)) && halfc[residual][k].find(l - aug - g[cand][k]) != halfc[residual][k].end()){
                        ans = true;
                        return;
                    }
            }
            else
                track2(i + 1);
            if(ans)
                return;
            aug -= g[tsp[i-1]][cand];
            mask -= 1 << cand;
            taken[cand] = 0;
    }
}

int main(){
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    if(n == 2){
        if(g[0][1] + g[1][0] == l)
            cout << "possible" << endl;
        else
            cout << "impossible" << endl;
        return 0;
    }
    if(n == 3){
        if(g[0][1] + g[1][2] + g[2][0] == l)
            cout << "possible" << endl;
        else
            cout << "impossible" << endl;
        return 0;
    }
    m = n / 2 + n % 2;
    track1(0);
    m = n / 2;
    tsp[0] = 0;
    mask = 1;
    track2(1);
    cout << (ans ? "possible" : "impossible") << endl;
}