#include <bits/stdc++.h>
using namespace std;

// Flow Finder

int n;
vector<int> adj[300003];
bool leaf[300003];
long long int flows[300003];

bool possible = true;

void bottom_up(int node){
    if(leaf[node])
        return;
    vector<int>& childs = adj[node];
    bool check = true;
    long long int sum = 0;
    for(int i = 0; i < childs.size(); i++){
        bottom_up(childs[i]);
        if(!flows[childs[i]])
            check = false;
        sum += flows[childs[i]];
    }
    if(check){
        if(flows[node]){
            if(flows[node] != sum)
                possible = false;
        }
        else flows[node] = sum;
    }
}

void top_down(int node){
    if(!flows[node]){
        possible = false;
        return;
    }
    if(leaf[node])
        return;
    int nd = 0;
    vector<int> & childs = adj[node];
    long long int sum = 0;
    for(int i = 0; i < childs.size(); i++){
        if(!flows[childs[i]])
            nd++;
        sum += flows[childs[i]];
    }
    if(!nd){
        if(sum != flows[node]){
            possible = false;
            return;
        }
        for(int i = 0; i < childs.size(); i++)
            top_down(childs[i]);
    }
    else if(nd == 1){
        long long int rem = flows[node] - sum;
        if(rem < 1){
            possible = false;
            return;
        }
        for(int i = 0; i < childs.size(); i++){
            if(!flows[childs[i]])
                flows[childs[i]] = rem;
            top_down(childs[i]);
        }
    }
    else{
        long long int rem = flows[node] - sum;
        if(rem != nd){
            possible = false;
            return;
        }
        for(int i = 0; i < childs.size(); i++){
            if(!flows[childs[i]])
                flows[childs[i]] = 1;
            top_down(childs[i]);
        }
    }
}

int main(){
    cin >> n;
    fill_n(leaf, n, true);
    int p;
    for(int i = 1; i < n; i++){
        cin >> p;
        adj[p-1].push_back(i);
        leaf[p-1] = false;
    }
    for(int i = 0; i < n; i++)
        cin >> flows[i];
    bottom_up(0);
    if(!possible){
        cout << "impossible" << endl;
        return 0;
    }
    top_down(0);
    if(!possible){
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cout << flows[i] << endl;
}