#include <bits/stdc++.h>
using namespace std;

// Trainsorting

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(!n){
            cout << 0 << endl;
            continue;
        }
        list<int> cars;
        while(n--){
            int x;
            cin >> x;
            cars.push_front(-x);
            cars.push_back(-x);
        }
        vector<int> lis;
        for(auto it = cars.begin(); it != cars.end(); it++){
            auto fi = lower_bound(lis.begin(), lis.end(), *it);
            if(fi == lis.end())
                lis.push_back(*it);
            else 
                *fi = *it;
        }
        cout << lis.size() << endl;
    } 

}