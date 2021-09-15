#include <bits/stdc++.h>
using namespace std;

// Secure Doors

set<string> building;

int main(){
    int n;
    cin >> n;
    while(n--){
        string name;
        cin >> name;
        if(name == "entry"){
            cin >> name;
            cout << name << " entered";
            if(building.find(name) == building.end())
                building.insert(name);
            else
                cout << " (ANOMALY)";
            cout << endl;
        }
        else if(name == "exit"){
            cin >> name;
            cout << name << " exited";
            if(building.find(name) == building.end())
                cout << " (ANOMALY)";
            else
                building.erase(name);
            cout << endl;
        }
    }
}