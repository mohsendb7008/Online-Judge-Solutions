#include <bits/stdc++.h>
using namespace std;

// Bounding Robots

int w, l, n;

int main(){
    while(1){
        cin >> w >> l;
        if(!(w + l))
            break;
        pair<int, int> thinks = {0, 0};
        pair<int, int> actual = {0, 0};
        cin >> n;
        while(n--){
            string x;
            int y;
            cin >> x >> y;
            if(x == "u")
                thinks.second += y, actual.second = min(actual.second + y, l - 1);
            else if(x == "d")
                thinks.second -= y, actual.second = max(actual.second - y, 0);
            else if(x == "r")
                thinks.first += y, actual.first = min(actual.first + y, w - 1);
            else if(x == "l")
                thinks.first -= y, actual.first = max(actual.first - y, 0);
        }
        cout << "Robot thinks " << thinks.first << " " << thinks.second << endl;
        cout << "Actually at " << actual.first << " " << actual.second << endl << endl;
    }
}