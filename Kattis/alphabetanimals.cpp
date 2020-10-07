#include <bits/stdc++.h>
using namespace std;

// Alphabet Animal

map<char, vector<string>> animals;
string str;
char q;
int n;

int main(){
    cin >> str;
    q = str[str.size()-1];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        animals[str[0]].push_back(str);
    }
    if(animals[q].empty()){
        cout << "?" << endl;
        return 0;
    }
    for(string animal : animals[q]){
        char c = animal[animal.size()-1];
        if((c != q && animals[c].empty()) || (c == q && animals[c].size() == 1)){
            cout << animal << "!" << endl;
            return 0;
        }
    }
    cout << animals[q][0] << endl; 
}