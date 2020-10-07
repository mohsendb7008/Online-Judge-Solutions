#include <bits/stdc++.h>
using namespace std;

// Helping Fill Bates

map<char, vector<int>> m;
string query;

int main(){
    vector<int> empty;
    for(char i = 'a'; i <= 'z'; i++)
        m[i] = empty;
    for(char i = 'A'; i <= 'Z'; i++)
        m[i] = empty;
    cin >> query;
    for(int i = 0; i < query.size(); i++)
        m[query[i]].push_back(i);
    int n;
    cin >> n;
    while(n--){
        cin >> query;
        if(m[query[0]].size() == 0){
            cout << "Not matched" << endl;
            continue;
        }
        int start_index = m[query[0]][0];
        int ptr = start_index;
        for(int i = 1; i < query.size(); i++){
            auto it = upper_bound(m[query[i]].begin(), m[query[i]].end(), ptr);
            if(it == m[query[i]].end()){
                ptr = -1;
                break;
            }
            ptr = *it;
        }
        if(ptr == -1){
            cout << "Not matched" << endl;
            continue;
        }
        cout << "Matched " << start_index << " " << ptr << endl; 
    }
}