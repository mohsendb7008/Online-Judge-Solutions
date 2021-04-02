#include <bits/stdc++.h>
using namespace std;

// Help Me With The Game

map<char, int> prio;

struct white{
    char t;
    int r, c;

    bool operator<(const white& o) const{
        if(this->t == o.t){
            if(this->r == o.r)
                return this->c < o.c;
            return this->r < o.r;
        }
        return prio[this->t] < prio[o.t];
    }

    void print(){
        if(t != 'P')
            cout << t;
        cout << char('a' + c) << r + 1;
    }
};

vector<white> whites;

struct black{
    char t;
    int r, c;

    bool operator<(const black& o) const{
        if(this->t == o.t){
            if(this->r == o.r)
                return this->c < o.c;
            return this->r > o.r;
        }
        return prio[this->t] < prio[o.t];
    }

    void print(){
        if(t != 'P')
            cout << t;
        cout << char('a' + c) << r + 1;
    }
};

vector<black> blacks;

int main(){
    prio['K'] = 1, prio['Q'] = 2, prio['R'] = 3, prio['B'] = 4, prio['N'] = 5, prio['P'] = 6;
    string line;
    getline(cin, line);
    int i = 0;
    while(getline(cin, line)){
        stringstream ss(line);
        char x;
        ss >> x;
        int j = 0;
        while(ss >> x){
            ss >> x;
            if(x >= 'A' && x <= 'Z'){
                white tmp;
                tmp.t = x, tmp.r = 7 - i, tmp.c = j;
                whites.push_back(tmp);
            }
            if(x >= 'a' && x <= 'z'){
                black tmp;
                tmp.t = x - 'a' + 'A', tmp.r = 7 - i, tmp.c = j;
                blacks.push_back(tmp);
            }
            ss >> x >> x;
            j++;
        }
        getline(cin, line);
        i++;
    }
    cout << "White: ";
    if(!whites.empty()){
        sort(whites.begin(), whites.end());
        for(int i = 0; i < whites.size() - 1; i++)
            whites[i].print(), cout << ',';
        whites[whites.size()-1].print();
    }
    cout << endl;
    cout << "Black: ";
    if(!blacks.empty()){
        sort(blacks.begin(), blacks.end());
        for(int i = 0; i < blacks.size() - 1; i++)
            blacks[i].print(), cout << ',';
        blacks[blacks.size()-1].print();
    }
    cout << endl;
}