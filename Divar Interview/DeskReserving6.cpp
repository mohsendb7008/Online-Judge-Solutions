#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, price;
int number_of_desks[maxn]; // number of desks in each floor
string type_floor[maxn];
string request, type_request, name, wanted_floor_type, reserve_facilities;
int duration;
string desk_type[maxn][maxn], desk_facilities[maxn][maxn];
vector<pair<int, int>> reserves[maxn][maxn]; // reserves of a specific desk
int ts, from_time, f, facility_price[13], needed_desk, max_budget;
string not_available = "no desk available";

inline int sum_facility_prices(const string& facilities);

inline int desk_price(int i, int j, int duration, int base_price){
    int total_price = base_price + duration * sum_facility_prices(desk_facilities[i][j]);
    return total_price;
}

pair<int, int> find_desk(const string& wanted_type, int start_time, int end_time, int max_budget = INT_MAX, bool check_facility=false, const string& reserve_facilities=""){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < number_of_desks[i]; j++){
            if(wanted_type != desk_type[i][j])
                break;
            if(check_facility && desk_facilities[i][j] != reserve_facilities)
                continue;
            if(desk_price(i, j, end_time - start_time + 1, (wanted_type == "special") ? price : 0) > max_budget)
                continue;
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

inline int sum_facility_prices(const string& facilities){
    int sum_ = 0;
    for(int i = 0; i < f; i++)
        sum_ += (facilities[i] == '1') * facility_price[i];
    return sum_;
}

bool find_desks(int start_time, int end_time, vector<pair<int, int>>& v, int needed_desks){
    for(int i = 0; i < n; i++){
        v.clear();
        for(int j = 0; j < number_of_desks[i]; j++){
            if("special" != desk_type[i][j])
                break;
            bool collision = false;
            for(pair<int, int> reserve: reserves[i][j]){
                if(!(start_time > reserve.second || reserve.first > end_time)){ // collision
                    collision = true;
                    break;
                }
            }
            if(!collision)
                v.push_back({i, j});
        }
        if(v.size() >= needed_desks)
            return true;
    }
    return false;
}

int main(){
    cin >> f;
    for(int i = 0; i < f; i++)
        cin >> facility_price[i];
    cin >> n >> price;
    for(int i = 0; i < n; i++){
        cin >> number_of_desks[i] >> type_floor[i];
        for(int j = 0; j < number_of_desks[i]; j++)
            desk_type[i][j] = type_floor[i], cin >> desk_facilities[i][j];
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
            string_stream >> wanted_floor_type >> duration >> max_budget;
            auto answer = find_desk(wanted_floor_type, ts, ts + duration - 1, max_budget);
            if(answer.first != -1){ // found a desk
                int i = answer.first, j = answer.second;
                int total_price = desk_price(i, j, duration, (wanted_floor_type == "special") ? price : 0);
                reserves[i][j].push_back({ts, ts + duration - 1});
                cout << name << " got desk " << i + 1 << "-" << j + 1 << " for " << total_price << endl; 
            }
            else
                cout << not_available << endl;
        }
        else if(type_request == "reserve_desk"){
            string_stream >> from_time >> duration >> reserve_facilities >> max_budget;
            auto answer = find_desk("special", from_time, from_time + duration - 1, max_budget, true, reserve_facilities);
            if(answer.first != -1){ // found a desk
                int i = answer.first, j = answer.second;
                int total_price = desk_price(i, j, duration, price);
                reserves[i][j].push_back({from_time, from_time + duration - 1});
                cout << name << " reserved desk " << i + 1 << "-" << j + 1 << " for " << total_price << endl;
            }
            else
                cout << not_available << endl;
        }
        else if(type_request == "reserve_multiple_desks"){
            string_stream >> needed_desk >> from_time >> duration;
            vector<pair<int, int>> answer;
            bool found = find_desks(from_time, from_time + duration - 1, answer, needed_desk);
            if(found){
                int total_price = 0;
                cout << name << " reserved desks  ";
                for(int i = 0; i < needed_desk; i++){
                    cout << answer[i].first + 1 << "-" << answer[i].second + 1 << " "; 
                    reserves[answer[i].first][answer[i].second].push_back({from_time, from_time + duration - 1});
                    total_price += price + duration * sum_facility_prices(desk_facilities[answer[i].first][answer[i].second]);
                }
                cout << "for " << total_price << endl;
            }
            else
                cout << "not enough desks available" << endl;
        }
    }
}