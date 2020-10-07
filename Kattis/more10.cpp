#include <bits/stdc++.h>
using namespace std;

// Mårten's Theorem

const int maxn = 2e5 + 3;

int n;
string line[maxn][3];
set<string> words;

string code(string s){
    if(s.size() <= 3)
        return s;
    return s.substr(s.size() - 3, 3);
}

map<string, int> id;

int par[maxn], ran[maxn];

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j])
        par[j] = i;
    else{
        par[i] = j;
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> line[i][0] >> line[i][1] >> line[i][2];
        line[i][0] = code(line[i][0]), line[i][2] = code(line[i][2]);
        words.insert(line[i][0]), words.insert(line[i][2]); 
    }
    int cnt = 0;
    for(string word : words){
        par[cnt] = cnt;
        id[word] = cnt++;
    }
    for(string word1 : words){
        if(word1.size() == 3){
            string word2 = word1.substr(1, 2);
            if(words.find(word2) != words.end())
                umerge(id[word1], id[word2]);
            word2 = word1.substr(2, 1);
            if(words.find(word2) != words.end())
                umerge(id[word1], id[word2]);
        }
        else if(word1.size() == 2){
            string word2 = word1.substr(1, 1);
            if(words.find(word2) != words.end())
                umerge(id[word1], id[word2]);
        }
    }
    for(int i = 0; i < n; i++)
        if(line[i][1] == "is")
            umerge(id[line[i][0]], id[line[i][2]]);
    for(int i = 0; i < n; i++){
        if(line[i][1] == "is"){
            if(ufind(id[line[i][0]]) != ufind(id[line[i][2]])){
                cout << "wait what?" << endl;
                return 0;
            }
        }
        else{
            if(ufind(id[line[i][0]]) == ufind(id[line[i][2]])){
                cout << "wait what?" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;         
}