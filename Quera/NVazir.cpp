#include <bits/stdc++.h>
using namespace std;

int n, k;
long long int ans = 0;
bool taken[13];
vector<pair<int, int>> knights;

void track(int row, int rem){
    if(row == n){
        ans++;
        return;
    }
    if(rem < n - row)
        track(row + 1, rem);
    if(rem){
        for(int col = 0; col < n; col++)
            if(!taken[col]){
                bool ok = 1;
                for(auto k : knights)
                    if(abs(row - k.first) == abs(col - k.second)){
                        ok = 0;
                        break;
                    }
                if(ok){
                    taken[col] = 1;
                    knights.push_back({row, col});
                    track(row + 1, rem - 1);
                    knights.pop_back();
                    taken[col] = 0;
                }
            }
    }
}

int main(){
    cin >> n >> k;
    if(k > n){
        cout << 0 << endl;
        return 0;
    }
    track(0, k);
    cout << ans << endl;
}