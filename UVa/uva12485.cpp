#include <bits/stdc++.h>
using namespace std;

// Perfect Choir

#define num long long int

num n;
vector<num> choirs;

int main(){
    while(cin >> n){
        choirs.clear();
        choirs.assign(n, 0);
        num sum = 0;
        for(int i = 0; i < n; i++)
            cin >> choirs[i], sum += choirs[i];
        if(sum % n){
            cout << -1 << endl;
            continue;
        }
        num distr = sum / n;
        num diff = 0;
        for(int i = 0; i < n; i++)
            diff += abs(distr - choirs[i]);
        if(diff % 2){
            cout << -1 << endl;
            continue;
        }
        cout << diff/2 + 1 << endl;
    }
}