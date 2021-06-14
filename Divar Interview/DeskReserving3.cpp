#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, price;
int number_of_desks[maxn]; // number of desks in each floor
string type_floor[maxn];
string request, type_request, name, wanted_floor_type;
int duration;
string desk_type[maxn][maxn];
vector<pair<int, int>> reserves[maxn][maxn]; // reserves of a specific desk
int ts, from_time;
string not_available = "no desk available";

pair<int, int> find_desk(string wanted_type, int start_time, int end_time){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < number_of_desks[i]; j++){
            if(wanted_type != desk_type[i][j])
                break;
            bool collision = false;
            for(pair<int, int> reserve: reserves[i][j]){
                if(!(start_time > reserve.second || reserve.first > end_time)){ // collision
                    collision = true;
                    break;
                }
            }
            if(!collision)
                return {i, j};
        }
    return {-1, -1};
}

int main(){
    cin >> n >> price;
    for(int i = 0; i < n; i++){
        cin >> number_of_desks[i] >> type_floor[i];
        for(int j = 0; j < number_of_desks[i]; j++)
            desk_type[i][j] = type_floor[i];
    }
    cin.ignore();
    while(1){
        getline(cin, request);
        stringstream string_stream(request);
        string unknown;
        string_stream >> unknown;
        if(unknown == "end")
            break;
        ts = stoi(unknown);
        string_stream >> type_request >> name;
        if(type_request == "request_desk"){
            string_stream >> wanted_floor_type >> duration;
            auto answer = find_desk(wanted_floor_type, ts, ts + duration - 1);
            if(answer.first != -1){ // found a desk
                int i = answer.first, j = answer.second;
                reserves[i][j].push_back({ts, ts + duration - 1});
                cout << name << " got desk " << i + 1 << "-" << j + 1;
                    if(wanted_floor_type == "special")
                        cout << " for " << price;
                    cout << endl;
            }
            else
                cout << not_available << endl;
        }
        else if(type_request == "reserve_desk"){
            string_stream >> from_time >> duration;
            auto answer = find_desk("special", from_time, from_time + duration - 1);
            if(answer.first != -1){ // found a desk
                int i = answer.first, j = answer.second;
                reserves[i][j].push_back({from_time, from_time + duration - 1});
                cout << name << " reserved desk " << i + 1 << "-" << j + 1 << " for " << price << endl;
            }
            else
                cout << not_available << endl;
        }
    }
}