#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
num k;
vector<pair<num, num>> fruits;

int main(){
    cin >> n >> k;
    num b, a;
    while(n--){
        cin >> b >> a;
        if(a > b)
            fruits.push_back({b, a});
    }
    sort(fruits.begin(), fruits.end());
    for(auto fruit : fruits)
        if(k >= fruit.first)
            k += fruit.second - fruit.first;
    cout << k << endl;
}