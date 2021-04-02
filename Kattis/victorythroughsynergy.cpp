#include <bits/stdc++.h>
using namespace std;

// Victory Through Synergy

int n = 10, m;
vector<int> adj[13];
string name[13], country[13], league[13], team[13];
vector<int> f{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int synergy(int i, int j){
    if(country[i] == country[j] && team[i] == team[j])
        return 3;
    if(country[i] == country[j] && league[i] == league[j])
        return 2;
    if(team[i] == team[j])
        return 2;
    if(league[i] == league[j])
        return 1;
    if(country[i] == country[j])
        return 1;
    return 0;
}

bool check(){
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j : adj[i])
            sum += synergy(f[i], f[j]);
        if(sum < adj[i].size())
            return false;
    }
    return true;
}

int main(){
    int u, v;
    cin >> m;
    while(m--)
        cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    for(int i = 0; i < 10; i++)
        cin >> name[i] >> country[i] >> league[i] >> team[i];
    do{
        if(check()){
            cout << "yes" << endl;
            return 0;
        }
    }while(next_permutation(f.begin(), f.end()));
    cout << "no" << endl;
}