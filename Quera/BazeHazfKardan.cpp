#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int n;
pair<int, int> intervals[MAX_N + 3];
vector<pair<int, int>> processed;

int main() 
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals, intervals + n);
    processed.push_back(intervals[0]);
    for(int i = 1; i < n; i++){
        if(intervals[i].first <= processed.back().second) {
            int last = int(processed.size()) - 1;
            processed[last].second = max(processed[last].second, intervals[i].second);
        }
        else {
            processed.push_back(intervals[i]);
        }
    }
    if(processed.front().first == 1 && processed.back().second == 100) {
        cout << int(processed.size()) - 1 << endl;
    } else {
        cout << -1 << endl;
    }
}
