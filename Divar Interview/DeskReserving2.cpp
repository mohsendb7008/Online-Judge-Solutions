#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, price;
int number_of_desks[maxn]; // number of desks in each floor
string type_floor[maxn];
string request, type_request, name, wanted_floor_type;
int duration;
string desk_type[maxn][maxn];
pair<string, pair<int, int>> desk[maxn][maxn]; // {name, {start_time, end_time}} for specific desk
int ts;

int main(){
    cin >> n >> price;
    for(int i = 0; i < n; i++){
        cin >> number_of_desks[i] >> type_floor[i];
        for(int j = 0; j < number_of_desks[i]; j++)
            desk_type[i][j] = type_floor[i];
    }
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
        string_stream >> type_request >> name >> wanted_floor_type >> duration;
        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < number_of_desks[i]; j++){
                if(wanted_floor_type != desk_type[i][j])
                    break;
                if(desk[i][j].second.second < ts){
                    desk[i][j] = {name, {ts, ts + duration - 1}};
                    found = true;
                    cout << name << " got desk " << i + 1 << "-" << j + 1;
                    if(wanted_floor_type == "special")
                        cout << " for " << price;
                    cout << endl;
                    break;
                }
            }
            if(found)
                break;
        }
        if(!found)
            cout << "no desk available" << endl;
    }
}