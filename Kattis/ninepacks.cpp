#include <bits/stdc++.h>
using namespace std;

// Nine Packs

#define inf INT_MAX

int H, B;
int hotdogs[103];
int buns[103];

int dph[103][100003];
int dpb[103][100003];

int main(){
    cin >> H;
    for(int i = 0; i < H; i++)
        cin >> hotdogs[i];
    cin >> B;
    for(int i = 0; i < B; i++)
        cin >> buns[i];
    for(int i = 0; i <= H; i++){
        for(int w = 0; w <= 100000; w++){
            if(i == 0)
                dph[i][w] = w ? inf : 0;
            else{
                dph[i][w] = dph[i-1][w];
                if(w >= hotdogs[i-1] && dph[i-1][w-hotdogs[i-1]] != inf)
                    dph[i][w] = min(dph[i][w], 1 + dph[i-1][w-hotdogs[i-1]]);
            }
        }
    }
    for(int i = 0; i <= B; i++){
        for(int w = 0; w <= 100000; w++){
            if(i == 0)
                dpb[i][w] = w ? inf : 0;
            else{
                dpb[i][w] = dpb[i-1][w];
                if(w >= buns[i-1] && dpb[i-1][w-buns[i-1]] != inf)
                    dpb[i][w] = min(dpb[i][w], 1 + dpb[i-1][w-buns[i-1]]);
            }
        }
    }
    int ans = inf;
    for(int w = 1; w <= 100000; w++)
        if(dph[H][w] != inf && dpb[B][w] != inf)
            ans = min(ans, dph[H][w] + dpb[B][w]);
    if(ans == inf)
        cout << "impossible" << endl;
    else cout << ans << endl;
}