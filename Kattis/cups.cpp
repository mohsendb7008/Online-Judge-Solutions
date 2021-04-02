#include <bits/stdc++.h>
using namespace std;

// Stacking Cups

int n;
pair<int, string> cups[23];

int main(){
    string x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(x[0] >= 'a' && x[0] <= 'z')
            cups[i] = {stoi(y), x};
        else
            cups[i] = {stoi(x) / 2, y};
    }
    sort(cups, cups + n);
    for(int i = 0; i < n; i++)
        cout << cups[i].second << endl;
}