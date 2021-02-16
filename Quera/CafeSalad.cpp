#include<bits/stdc++.h>
using namespace std;

int days;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
set<string> names, tmp;

int main(){
    cin >> days;
    for(int i = 0; i < days; i++){
        tmp.clear();
        int k;
        cin >> k;
        for(int j = 0; j <k; j++){
            string name;
            int x;
            cin >> name >> x;
            names.insert(name);
            pq.push({x+i-1, name});
        }
        while(!pq.empty()){
            auto it = pq.top();
            if(it.first > i)
                break;
            pq.pop();
            auto it2 = names.find(it.second);
            if(it2 == names.end())
                continue;
            names.erase(it2);
            tmp.insert(it.second);
        }
        if(!names.empty()){
            tmp.insert(*names.begin());
            names.erase(names.begin());
        }
        for(auto i: tmp)
            cout << i << " ";
        cout << endl;
    }
}