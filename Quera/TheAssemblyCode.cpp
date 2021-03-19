#include <bits/stdc++.h>
using namespace std;

#define num unsigned int

vector<string> split(const string& str, char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

int n = 0, k;
vector<string> codes[103];
vector<string> inputs[103];

vector<string> instructions{"ADD", "MULT", "AND", "OR", "XOR"};
vector<string> candidate;
set<string> unknowns{"A", "B", "C", "D", "E"};

map<num, num> memory;

num rval(string s){
    if(s[0] == '#')
        return stoul(s.substr(1));
    else if(s[0] == '$')
        return memory[stoul(s.substr(1))];
    return memory[memory[stoul(s.substr(1))]];
}

num lval(string s){
    if(s[0] == '$')
        return stoul(s.substr(1));
    return memory[stoul(s.substr(1))];
}

bool run(int i){
    int ptr = 0;
    for(int j = 0; j < n - 1; j++){
        string c = codes[j][0];
        if(unknowns.find(c) != unknowns.end())
            c = instructions[c[0] - 'A'];
        if(c == "INPUT")
            memory[lval(codes[j][1])] = stoul(inputs[i][ptr++]);
        else if(c == "MOVE")
            memory[lval(codes[j][1])] = rval(codes[j][2]);
        else if(c == "ADD")
            memory[lval(codes[j][1])] = rval(codes[j][2]) + rval(codes[j][3]);
        else if(c == "MULT")
            memory[lval(codes[j][1])] = rval(codes[j][2]) * rval(codes[j][3]);
        else if(c == "AND")
            memory[lval(codes[j][1])] = rval(codes[j][2]) & rval(codes[j][3]);
        else if(c == "OR")
            memory[lval(codes[j][1])] = rval(codes[j][2]) | rval(codes[j][3]);
        else if(c == "XOR")
            memory[lval(codes[j][1])] = rval(codes[j][2]) ^ rval(codes[j][3]);
    }
    return rval(codes[n-1][1]) == stoul(inputs[i][ptr]);
}

bool check(){
    for(int i = 0; i < k; i++){
        memory.clear();
        if(!run(i))
            return false;
    }
    return true;
}

int main(){
    string c;
    while(true){
        getline(cin, c);
        codes[n++] = split(c, ' ');
        if(codes[n-1][0] == "OUTPUT")
            break;
    }
    cin >> k;
    cin.ignore();
    for(int i = 0; i < k; i++){
        getline(cin, c);
        inputs[i] = split(c, ' ');
    }
    int ans = 0;
    sort(instructions.begin(), instructions.end());
    do{
        if(check()){
            ans++;
            if(ans == 1)
                candidate = instructions;
        }
    }while(next_permutation(instructions.begin(), instructions.end()));
    cout << ans << endl;
    if(ans == 1){
        for(string c : candidate)
            cout << c << " ";
        cout << endl;
    }
}