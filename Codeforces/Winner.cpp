#include <bits/stdc++.h>
using namespace std;

map<string, int> score;
map<string, vector<pair<int, int>>> events;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string u;
        int v;
        cin >> u >> v;
        score[u] += v;
        events[u].push_back({score[u], i});
    }
    int max_score = 0;
    for(auto it : score)
        max_score = max(max_score, it.second);
    int min_event = INT_MAX;
    string winner;
    for(auto it : score)
        if(it.second == max_score)
            for(auto event : events[it.first])
                if(event.first >= max_score && event.second < min_event){
                    min_event = event.second, winner = it.first;
                    break;
                }
    cout << winner << endl;
}