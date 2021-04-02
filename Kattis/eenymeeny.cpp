#include <bits/stdc++.h>
using namespace std;

// Eeny Meeny

int n, k = 0;
vector<string> childs, team1, team2;

int main(){
    string line, word;
    getline(cin, line);
    stringstream ss(line);
    while(ss >> word)
        k++;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        childs.push_back(word);
    }
    int ptr = 0;
    bool flag = true;
    while(true){
        ptr = (ptr + k - 1) % childs.size();
        if(flag) team1.push_back(childs[ptr]);
        else team2.push_back(childs[ptr]);
        childs.erase(next(childs.begin(), ptr));
        if(childs.empty())
            break;
        ptr %= childs.size();
        flag = !flag;
    }
    cout << team1.size() << endl;
    for(string c : team1)
        cout << c << endl;
    cout << team2.size() << endl;
    for(string c : team2)
        cout << c << endl;
}