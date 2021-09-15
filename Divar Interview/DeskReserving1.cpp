#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n;
int number_of_desks[maxn]; // number of desks in each floor
string request, type_request, name;
int duration;
pair<string, pair<int, int>> desk[maxn][maxn]; // {name, {start_time, end_time}} for specific desk
int ts;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> number_of_desks[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < number_of_desks[i]; j++)
            desk[i][j].second.second = -1; // empty desk
    cin.ignore();
    while(1){
        getline(cin, request);
        stringstream string_stream(request);
        string unknown;
        string_stream >> unknown;
        if(unknown == "end")
            break;
        ts = stoi(unknown);
        string_stream >> type_request >> name >> duration;
        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < number_of_desks[i]; j++)
                if(desk[i][j].second.second < ts){
                    desk[i][j] = {name, {ts, ts + duration - 1}};
                    found = true;
                    cout << name << " got desk " << i + 1 << "-" << j + 1 << endl;
                    break;
                }
            if(found)
                break;
        }
        if(!found)
            cout << "no desk available" << endl;
    }
}