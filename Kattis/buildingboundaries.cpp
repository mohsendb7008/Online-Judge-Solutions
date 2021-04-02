#include <bits/stdc++.h>
using namespace std;

// Building Boundaries

vector<pair<long long int, long long int>> squares;
bool rotation[3];
long long int ans;
void track(int i){
    if(i == 3){
        long long int a1 = squares[0].first, b1 = squares[0].second;
        if(rotation[0])
            swap(a1, b1);
        long long int a2 = squares[1].first, b2 = squares[1].second;
        if(rotation[1])
            swap(a2, b2);
        long long int a3 = squares[2].first, b3 = squares[2].second;
        if(rotation[2])
            swap(a3, b3);
        ans = min(ans, (a1 + a2 + a3) * max(b1, max(b2 ,b3)));
        ans = min(ans, ((a1 + max(a2, a3)) * max(b1, b2 + b3)));
        long long int th;
        ans = min(ans, max(a1 + a2, a3) * max(b1 + b3, b2 + b3));
        return;
    }
    rotation[i] = true;
    track(i+1);
    rotation[i] = false;
    track(i+1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        squares.clear();
        long long int x, y;
        for(int i = 0; i < 3; i++)
            cin >> x >> y, squares.push_back({x, y});
        sort(squares.begin(), squares.end());
        ans = LLONG_MAX;
        do{
            track(0);
        }while(next_permutation(squares.begin(), squares.end()));
        cout << ans << endl;
    }
}