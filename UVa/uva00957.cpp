#include <bits/stdc++.h>
using namespace std;

// Popes

int y, p;
vector<int> popes;

int main(){
    while(cin >> y){
        cin >> p;
        popes.clear();
        for(int i = 0; i < p; i++){
            int x;
            cin >> x;
            popes.push_back(x);
        }
        int ans = 1, i = 0, j = 0;
        for(int first = 0; first < popes.size(); first++){
            int second = upper_bound(popes.begin(), popes.end(), popes[first] + y - 1) - popes.begin();
            if(second - first > ans){
                ans = second - first;
                i = first;
                j = second-1;
            }
        }
        cout << ans << " " << popes[i] << " " << popes[j] << endl; 
    }
}