#include <bits/stdc++.h>
using namespace std;

// Set!

string cards[12 + 3];

inline bool same(int i, int j, int k, int d){
    return cards[i][d] == cards[j][d] && cards[j][d] == cards[k][d];
}

inline bool different(int i, int j, int k, int d){
    return cards[i][d] != cards[j][d] && cards[i][d] != cards[k][d] && cards[j][d] != cards[k][d];
}

inline bool good(int i, int j, int k){
    return (same(i, j, k, 0) || different(i, j, k, 0)) && 
        (same(i, j, k, 1) || different(i, j, k, 1)) && 
        (same(i, j, k, 2) || different(i, j, k, 2)) && 
        (same(i, j, k, 3) || different(i, j, k, 3));
}

int main(){
    for(int i = 0; i < 12; i++)
        cin >> cards[i];
    bool ans = false;
    for(int i = 0; i < 12; i++)
        for(int j = i + 1; j < 12; j++)
            for(int k = j + 1; k < 12; k++)
                if(good(i, j, k)){
                    ans = true;
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                }
    if(!ans)
        cout << "no sets" << endl;
}