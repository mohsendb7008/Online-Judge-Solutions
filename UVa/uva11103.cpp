#include <bits/stdc++.h>
using namespace std;

// WFF'N PROOF

string line;

vector<char> operands;
int not_counts;
vector<char> operators;

void extract(string line){
    operands.clear();
    not_counts = 0;
    operators.clear();
    for(char c : line){
        if(c == 'N')
            not_counts++;
        else if(c >= 'a' && c <= 'z')
            operands.push_back(c);
        else
            operators.push_back(c);
    }
}

void print_tree(){
    if(operands.size() == 1 || operators.empty()){
        if(not_counts)
            cout << 'N';
        cout << operands[0] << endl;
        return;
    }
    if(not_counts){
        cout << 'N';
        not_counts--;
    }
    cout << operators[operators.size()-1];
    operators.pop_back();
    if(not_counts){
        cout << 'N';
        not_counts--;
    }
    cout << operands[operands.size()-1];
    operands.pop_back();
    print_tree();
}

int main(){
    while(1){
        getline(cin, line);
        if(line == "0")
            break;
        extract(line);
        if(operands.empty()){
            cout << "no WFF possible" << endl;
            continue;
        }
        print_tree();
    }
}