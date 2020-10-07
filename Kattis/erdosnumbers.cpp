#include <bits/stdc++.h>
using namespace std;

// Erdős Numbers

int n = 0;
string names[2003];
map<string, vector<string>> adj;
map<string, int> dis;
queue<string> bfs;

int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string u, v;
        ss >> u;
        names[n++] = u;
        while(ss >> v)
            adj[u].push_back(v), adj[v].push_back(u);
    }
    dis["PAUL_ERDOS"] = 0;
    bfs.push("PAUL_ERDOS");
    while(!bfs.empty()){
        string u = bfs.front();
        bfs.pop();
        for(string v : adj[u])
            if(dis.find(v) == dis.end())
                dis[v] = dis[u] + 1, bfs.push(v);    
    }
    for(int i = 0; i < n; i++){
        cout << names[i] << " ";
        if(dis.find(names[i]) == dis.end())
            cout << "no-connection" << endl;
        else
            cout << dis[names[i]] << endl; 
    }   
}