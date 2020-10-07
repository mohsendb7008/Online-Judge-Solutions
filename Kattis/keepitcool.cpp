#include <bits/stdc++.h>
using namespace std;

// Keep it Cool

int n, m, s, d, sum = 0;
pair<int, int> slot[103];
pair<int, int> rfill[103];

int main(){
    cin >> n >> m >> s >> d;
    for(int i = 0; i < s; i++)
        cin >> slot[i].first, slot[i].second = i, sum+= slot[i].first;
    sort(slot, slot+s);
    for(int i = 0; i < s; i++){
        rfill[i].first = slot[i].second;
        rfill[i].second = 0;
    }
    for(int i = 0; i < s; i++){
        if(n == 0)
            break;
        sum -= slot[i].first;
        rfill[i].second = min(n, d - slot[i].first); 
        n -= min(n, d - slot[i].first);
    }
    if(sum >= m){
        sort(rfill, rfill+s);
        for(int i = 0; i < s; i++)
            cout << rfill[i].second << " ";
        cout << endl;
    }
    else{
        cout << "impossible" << endl;
    }
}