#include <bits/stdc++.h>
using namespace std;

// Free Food

int n, food[366];

int main(){
    cin >> n;
    while(n--){
        int s, t;
        cin >> s >> t;
        for(int i = s; i <= t; i++)
            food[i] = 1;
    }
    cout << count(food, food + 366, 1) << endl;
}