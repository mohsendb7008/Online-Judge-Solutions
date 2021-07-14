#include <bits/stdc++.h>
using namespace std;

// Bacon, Eggs, and Spam

map<string, set<string>> orders;

int main(){
    while(1){
        orders.clear();
        int n;
        cin >> n;
        if(!n)
            break;
        cin.ignore();
        while(n--){
            string line;
            getline(cin, line);
            stringstream ss(line);
            string name, order;
            ss >> name;
            while(ss >> order)
                orders[order].insert(name);
        }
        for(pair<string, set<string>> it: orders){
            cout << it.first << " ";
            for(string name : it.second)
                cout << name << " ";
            cout << endl;
        }
        cout << endl;
    }
}