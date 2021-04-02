#include <bits/stdc++.h>
using namespace std;

// Crop Triangles(Easy)

#define num long long int

int n;
vector<pair<num, num>> trees;

num A, B, C, D, xz, yz, M;

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        trees.clear();
        cin >> n >> A >> B >> C >> D >> xz >> yz >> M;
        num x = xz, y = yz;
        trees.push_back({x, y});
        for(int i = 1; i < n; i++){
            x = (A * x + B) % M;
            y = (C * y + D) % M;
            trees.push_back({x, y});
        }
        num ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++){
                    num xsum = trees[i].first + trees[j].first + trees[k].first;
                    num ysum = trees[i].second + trees[j].second + trees[k].second;
                    if((xsum % 3 == 0) && (ysum % 3 == 0))
                        ans++;
                }
        cout << "Case #" << test << ": " << ans << endl;
    }
}