#include <bits/stdc++.h>
using namespace std;

int n, k;
set<pair<int, int>> horse;

int adjR[8]{2, 2, -2, -2, 1, 1, -1, -1};
int adjC[8]{1, -1, 1, -1, 2, -2, 2, -2};

void track(int i, int j, int k){
    if(!k){
        horse.insert({i, j});
        return;
    }
    for(int z = 0; z < 8; z++){
        int x = i + adjR[z], y = j + adjC[z];
        if(x >= 0 && x < n && y >= 0 && y < n)
            track(x, y, k - 1);
    }
}

int main(){
    cin >> n >> k;
    track(0, 0, k);
    cout << horse.size() << endl;
}