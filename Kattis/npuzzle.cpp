// N-Puzzle

#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> correct{
    {'A', {0, 0}},
    {'B', {0, 1}},
    {'C', {0, 2}},
    {'D', {0, 3}},
    {'E', {1, 0}},
    {'F', {1, 1}},
    {'G', {1, 2}},
    {'H', {1, 3}},
    {'I', {2, 0}},
    {'J', {2, 1}},
    {'K', {2, 2}},
    {'L', {2, 3}},
    {'M', {3, 0}},
    {'N', {3, 1}},
    {'O', {3, 2}}
};

int main(){
    int ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            char g;
            cin >> g;
            if(g == '.'){
                continue;
            }
            ans += abs(i - correct[g].first) + abs(j - correct[g].second);
        }
    }
    cout << ans << endl;
}