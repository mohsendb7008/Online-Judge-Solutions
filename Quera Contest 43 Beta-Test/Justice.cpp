#include <bits/stdc++.h>
using namespace std;

vector<int> row;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        if(i < k % n){
            row.push_back(k / n + 1);
        }
        else{
            row.push_back(k / n);
        }
    }
    for(int i = 0; i < n; i++){
        for(int item: row){
            cout << item << " ";
        }
        cout << endl;
        rotate(row.begin(), next(row.begin()), row.end());
    }
}