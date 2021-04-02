#include <bits/stdc++.h>
using namespace std;

// Rubik's Revenge in ... 2D!? 3D?

map<string, int> dis[2];
queue<pair<string, int>> bfs;

vector<string> adj;

inline void prow(string u, int i, int d){
    char g[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            g[i][j] = u[i * 4 + j];
    if(d){
        int tmp = g[i][3];
        for(int j = 3; j > 0; j--)
            g[i][j] = g[i][j-1];
        g[i][0] = tmp;
    }else{
        int tmp = g[i][0];
        for(int j = 0; j < 3; j++)
            g[i][j] = g[i][j+1];
        g[i][3] = tmp;
    }
    string v = "";
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            v += g[i][j];
    adj.push_back(v);
}

inline void pcol(string u, int j, int d){
    char g[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            g[i][j] = u[i * 4 + j];
    if(d){
        int tmp = g[3][j];
        for(int i = 3; i > 0; i--)
            g[i][j] = g[i-1][j];
        g[0][j] = tmp;
    }else{
        int tmp = g[0][j];
        for(int i = 0; i < 3; i++)
            g[i][j] = g[i+1][j];
        g[3][j] = tmp;
    }
    string v = "";
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            v += g[i][j];
    adj.push_back(v);
}

inline void produce(string u){
    adj.clear();
    for(int i = 0; i < 4; i++)
        prow(u, i, 0), prow(u, i, 1);
    for(int j = 0; j < 4; j++)
        pcol(u, j, 0), pcol(u, j, 1);
}

int main(){
    string s, g = "";
    for(int i = 0; i < 4; i++)
        cin >> s, g += s;
    if(g == "RRRRGGGGBBBBYYYY"){
        cout << 0 << endl;
        return 0;
    }
    dis[0][g] = 0;
    bfs.push({g, 0});
    dis[1]["RRRRGGGGBBBBYYYY"] = 0;
    bfs.push({"RRRRGGGGBBBBYYYY", 1});
    adj.reserve(16);
    while(!bfs.empty()){
        string u = bfs.front().first;
        int d = bfs.front().second;
        bfs.pop();
        produce(u);
        for(string v : adj)
            if(dis[1-d].find(v) != dis[1-d].end()){
                cout << dis[d][u] + dis[1-d][v] + 1 << endl;
                return 0;
            }
        for(string v : adj)
            if(dis[d].find(v) == dis[d].end())
                dis[d][v] = dis[d][u] + 1, bfs.push({v, d});
    }
}