// MrCodeFormatGrader

#include <bits/stdc++.h>
using namespace std;

const int max_c = 1e5 + 3;

int C, n;
bool a[max_c];

vector<pair<int, int>> out[2];

int main(){
    cin >> C >> n;
    while(n--){
        int x;
        cin >> x;
        a[x] = 1;
    }
    int ptr = 1;
    bool error = a[1];
    for(int i = 2; i <= C; i++){
        if(a[i] == a[ptr]){
            continue;
        }
        out[error].push_back({ptr, i-1});
        ptr = i;
        error = !error;
    }
    out[error].push_back({ptr, C});
    cout << "Errors: ";
    for(int i = 0; i < out[1].size(); i++){
        auto it = out[1][i];
        if(it.first == it.second){
            cout << it.first;
        }
        else{
            cout << it.first << "-" << it.second;
        }
        if(i < int(out[1].size()) - 2){
            cout << ", ";
        }
        else if(i == int(out[1].size()) - 2){
            cout << " and ";
        }
    }
    cout << endl << "Correct: ";
    for(int i = 0; i < out[0].size(); i++){
        auto it = out[0][i];
        if(it.first == it.second){
            cout << it.first;
        }
        else{
            cout << it.first << "-" << it.second;
        }
        if(i < int(out[0].size()) - 2){
            cout << ", ";
        }
        else if(i == int(out[0].size()) - 2){
            cout << " and ";
        }
    }
    cout << endl;
}