#include <bits/stdc++.h>
using namespace std;

// Train Passengers

int c, n;

int main(){
    cin >> c >> n;
    int train, left, entered, wait;
    for(int i = 0; i < n; i++){
        cin >> left >> entered >> wait;
        if(i == 0){
            if(left){
                cout << "impossible" << endl;
                return 0;
            }
            train = entered;
            if(train > c){
                cout << "impossible" << endl;
                return 0;
            }
            if(wait && train < c){
                cout << "impossible" << endl;
                return 0;
            }
        }
        else if(i == n-1){
            if(!(left == train && !entered && !wait)){
                cout << "impossible" << endl;
                return 0;
            }
        }
        else{
            train -= left;
            if(train < 0){
                cout << "impossible" << endl;
                return 0;
            }
            train += entered;
            if(train > c){
                cout << "impossible" << endl;
                return 0;
            }
            if(wait && train < c){
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
}