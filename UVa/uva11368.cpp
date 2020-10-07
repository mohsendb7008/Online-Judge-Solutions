#include <bits/stdc++.h>
using namespace std;

// Nested Dolls

// Dilworth Theorem!

int n;
pair<int, int> dolls[20003];
vector<int> lds;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> dolls[i].first >> dolls[i].second, dolls[i].second *= -1;
        sort(dolls, dolls+n);
        lds.clear();
        lds.push_back(dolls[0].second);
        for(int i = 1; i < n; i++){
            auto it = upper_bound(lds.begin(), lds.end(), dolls[i].second);
            if(it == lds.end())
                lds.push_back(dolls[i].second);
            else
                *it = dolls[i].second;
        }
        cout << lds.size() << endl;
    }
}