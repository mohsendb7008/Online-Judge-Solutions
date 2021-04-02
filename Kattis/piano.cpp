#include <bits/stdc++.h>
using namespace std;

// Moving Pianos

int m, p, freee, workers;
pair<int, int> intervals[1003];

inline bool solve(){
    for(int i = 0; i < m; i++){
        int a = intervals[i].first, b = intervals[i].second;
        if(freee < a){
            freee = a;
            if(freee % 7 == 0)
                freee++;
            else if(freee % 7 == 6)
                freee += 2;
            workers = p;
        }
        if(freee > b)
            return false;
        workers--;
        if(!workers){
            freee++;
            if(freee % 7 == 0)
                freee++;
            else if(freee % 7 == 6)
                freee += 2;
            workers = p;
        }
    }
    return true;
}

inline bool weekends(){
    for(int i = 0; i < m; i++){
        int a = intervals[i].first, b = intervals[i].second;
        if(freee < a){
            freee = a;
            workers = p;
        }
        if(freee > b)
            return false;
        workers--;
        if(!workers){
            freee++;
            workers = p;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> m >> p;
        for(int i = 0; i < m; i++)
            cin >> intervals[i].first >> intervals[i].second;
        if(p < 2){
            cout << "serious trouble" << endl;
            continue;
        }
        sort(intervals, intervals+m);
        p /= 2;
        freee = -1;
        workers = p;
        if(solve()){
            cout << "fine" << endl;
            continue;
        }
        freee = -1;
        workers = p;
        if(weekends()){
            cout << "weekend work" << endl;
            continue;
        }
        cout << "serious trouble" << endl;
    }
}