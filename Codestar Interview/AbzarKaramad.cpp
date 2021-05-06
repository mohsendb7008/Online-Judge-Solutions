#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& str){
    stringstream ss(str);
    string token;
    vector<string> ans;
    while(getline(ss, token, ' '))
        ans.push_back(token);
    return ans;
}

vector<int> asplit(string& str){
    stringstream ss(str);
    string token;
    vector<int> ans;
    while(getline(ss, token, ' '))
        ans.push_back(stoi(token));
    return ans;
}

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int n, m, c, p, t, q;
vector<vector<int>> families, moves;
vector<vector<string>> experiments;

map<int, set<int>> family_of;
map<int, set<int>> covid;

void preprocess(){
    for(auto family : families)
        for(auto person : family)
            for(auto member : family)
                family_of[person].insert(member);
    for(auto experiment : experiments){
        if(experiment[1] == "negative")
            continue;
        int day = stoi(experiment[3]);
        for(int i = 0; i < 8; i++)
            for(auto person : family_of[stoi(experiment[0])])
                covid[day + i].insert(person);
    }
}

vector<pair<int, int>> ready(map<int, int> data, int N){
    vector<pair<int, int>> ans;
    for(int i = 1; i <= N; i++)
        ans.push_back({i, data[i]});
    sort(ans.begin(), ans.end(), cmp);
    return ans;
}

vector<pair<int, int>> q1(int start_day = 1, int end_day = 365){
    map<int, int> ans;
    for(auto move : moves){
        if(move[1] == move[2] || move[3] < start_day || move[3] > end_day)
            continue;
        if(covid[move[3]].find(move[0]) != covid[move[3]].end())
            ans[move[0]]++;
    }
    return ready(ans, n);
}

vector<pair<int, int>> q2(int start_day = 1, int end_day = 365){
    map<int, int> ans;
    for(auto experiment : experiments){
        if(experiment[1] == "negative")
            continue;
        int day = stoi(experiment[3]);
        if(day >= start_day && day <= end_day)
            ans[stoi(experiment[0])]++;
    }
    return ready(ans, n);
}

vector<pair<int, int>> q3(int start_day = 1, int end_day = 365){
    map<int, int> ans;
    for(auto experiment : experiments){
        if(experiment[1] == "negative")
            continue;
        int day = stoi(experiment[3]);
        if(day >= start_day && day <= end_day)
            ans[stoi(experiment[2])]++;
    }
    return ready(ans, c);
}

vector<pair<int, int>> q4(int city){
    map<int, int> ans;
    for(auto experiment : experiments){
        if(experiment[1] == "negative" || stoi(experiment[2]) != city)
            continue;
        int day = stoi(experiment[3]);
        ans[day]++;
    }
    return ready(ans, 365);
}

vector<pair<int, int>> q5(){
    map<int, int> ans;
    for(auto co : covid)
        ans[co.first] = co.second.size();
    return ready(ans, 365);
}

void print(vector<pair<int, int>> data, int count){
    for(int i = 0; i < count; i++)
        cout << data[i].first << ' ' << data[i].second << '\n';
}

int main(){
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < m; i++){
        string s;
        getline(cin, s);
        families.push_back(asplit(s));
    }
    cin >> c >> p;
    cin.ignore();
    for(int i = 0; i < p; i++){
        string s;
        getline(cin, s);
        moves.push_back(asplit(s));
    }
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++){
        string s;
        getline(cin, s);
        experiments.push_back(split(s));
    }
    preprocess();
    cin >> q;
    cin.ignore();
    while(q--){
        string s;
        getline(cin, s);
        vector<string> cmd = split(s);
        cout << cmd[0] << '\n';
        if(cmd[0] == "Q1"){
            if(cmd.size() == 2)
                print(q1(), stoi(cmd[1]));
            else
                print(q1(stoi(cmd[2]), stoi(cmd[3])), stoi(cmd[1]));
        }
        else if(cmd[0] == "Q2"){
            if(cmd.size() == 2)
                print(q2(), stoi(cmd[1]));
            else
                print(q2(stoi(cmd[2]), stoi(cmd[3])), stoi(cmd[1]));
        }
        else if(cmd[0] == "Q3"){
            if(cmd.size() == 2)
                print(q3(), stoi(cmd[1]));
            else
                print(q3(stoi(cmd[2]), stoi(cmd[3])), stoi(cmd[1]));
        }
        else if(cmd[0] == "Q4")
            print(q4(stoi(cmd[1])), stoi(cmd[2]));
        else if(cmd[0] == "Q5")
            print(q5(), stoi(cmd[1]));
    }
}