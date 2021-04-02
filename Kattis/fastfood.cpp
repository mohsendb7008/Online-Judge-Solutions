#include <bits/stdc++.h>
using namespace std;

// Fast Food Prizes

#define num long long int

int n, m;
vector<int> cards_needed[13];
num prize[13];
int have[33];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0 ; i < n; i++)
            cards_needed[i].clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            while(x--){
                int y;
                cin >> y;
                y--;
                cards_needed[i].push_back(y);
            }
            cin >> prize[i];
        }
        for(int i = 0; i < m; i++)
            cin >> have[i];
        num ans = 0;
        for(int i = 0; i < n; i++){
            int min_card = INT_MAX;
            for(int x : cards_needed[i])
                min_card = min(min_card, have[x]);
            ans += prize[i] * min_card;
        }       
        cout << ans << endl;
    }
}