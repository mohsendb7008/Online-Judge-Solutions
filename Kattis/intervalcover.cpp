#include <bits/stdc++.h>
using namespace std;

// Interval Cover

struct interval{
    double first, second;
    int index;
};

double A, B;
int n;
vector<interval> intervals;

vector<int> indices;

int solve(){ // -1 is impossible
    if(intervals.empty())
        return -1;
    if(intervals[0].first > A)
        return -1;
    int ans = 1;
    indices.push_back(intervals[0].index);
    int ptr = 0;
    double coverage = intervals[0].second;
    if(coverage >= B)
        return ans;
    while(ptr < n){
        bool found = false;
        double max_cov;
        int candidate;
        for(int j = ptr + 1; j < n; j++)
            if(intervals[j].first <= coverage && intervals[j].second > coverage){
                if(!found){
                    found = true;
                    max_cov = intervals[j].second;
                    candidate = j;
                }
                else if(intervals[j].second >= max_cov){
                    max_cov = intervals[j].second;
                    candidate = j;
                }
            }
        if(!found)
            return -1;
        ans++;
        indices.push_back(intervals[candidate].index);
        ptr = candidate;
        coverage = intervals[candidate].second;
        if(coverage >= B)
            return ans;
    }
    return -1;
}

int main(){
    while(cin >> A >> B >> n){
        intervals.clear();
        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            if(y < A || x > B)
                continue;
            interval in;
            in.first = max(A, x),
            in.second = min(B, y);
            in.index = i;
            intervals.push_back(in);
        }
        n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const interval& i1, const interval& i2){
            if(i1.first == i2.first)
                return i1.second - i1.first > i2.second - i2.first;
            return i1.first < i2.first;
        });
        indices.clear();
        int ans = solve();
        if(ans == -1)
            cout << "impossible" << endl;
        else{
            cout << ans << endl;
            for(int ind : indices)
                cout << ind << " ";
            cout << endl;
        }
    }
}