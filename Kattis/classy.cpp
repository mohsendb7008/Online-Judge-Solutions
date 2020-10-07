#include <bits/stdc++.h>
using namespace std;

// A Classy Problem

string tokenize(string s){
    string ans = "";
    stringstream ss(s);
    string token;
    while(getline(ss, token, '-')){
        if(token == "upper")
            ans += '3';
        else if(token == "lower")
            ans += '1';
        else 
            ans += '2';
    }
    return ans;
}

int n;
struct per{
    string name, clas;
} persons[103];

bool cmp(const per& p1, const per& p2){
    for(int i = 0; i < max(p1.clas.size(), p2.clas.size()); i++){
        char c1 = (i >= p1.clas.size()) ? '2' : p1.clas[i], c2 = (i >= p2.clas.size()) ? '2' : p2.clas[i];
        if(c1 > c2)
            return true;
        else if(c1 < c2)
            return false;
    }
    return p1.name < p2.name;   
}

int main(){
    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> persons[i].name >> persons[i].clas >> s, persons[i].name.pop_back(), persons[i].clas = tokenize(persons[i].clas), reverse(persons[i].clas.begin(), persons[i].clas.end());
        sort(persons, persons + n, cmp);
        for(int i = 0; i < n; i++)
            cout << persons[i].name << endl;
        for(int i = 0; i < 30; i++)
            cout << "=";
        cout << endl;
    }
}