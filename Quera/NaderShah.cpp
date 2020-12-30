#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v, w, afshari;
    edge(int v, int w, int afshari){
        this->v = v;
        this->w = w;
        this->afshari = afshari;
    }
    bool operator<(const edge & other) const{
        return this->v > other.v;
    }
};

int V, E;
vector<edge> graph[1003];

bool taken[1003];

int indeg[1003];
vector<int> dependency[1003];

void naderShah(int iran){
    fill_n(taken, V, false);
    fill_n(indeg, V, 0);
    for(int i = 0; i < V; i++)
        dependency[i].clear();

    priority_queue<edge> pq;
    taken[iran] = true;
    for(edge x: graph[iran]){
        if(x.afshari){
            pq.push(x);
            dependency[iran].push_back(x.v);
            indeg[x.v]++;
        }
    }
    
    while(!pq.empty()){
        edge x = pq.top();
        pq.pop();
        taken[x.v] = true;
        for(edge y: graph[x.v]){
            if(!y.afshari && y.w < x.w){
                dependency[x.v].push_back(y.v);
                indeg[y.v]++;
            }
            if(y.afshari && !taken[y.v]){
                pq.push(y);
                dependency[x.v].push_back(y.v);
                indeg[y.v]++;
            }
        }
    }
}

vector<int> order;

bool kahn(){
    order.clear();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < V; i++)
        if(!indeg[i])
            pq.push(i);
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for(int v : dependency[u]){
            indeg[v]--;
            if(!indeg[v])
                pq.push(v);
        }
    }
    return order.size() == V;
}

int main(){
    scanf("%d %d", &V, &E);

    for(int i = 0; i < E; i++){
        int u, v, w, afshari;
        scanf("%d %d %d %d", &u, &v, &w, &afshari);
        graph[u-1].push_back(edge(v-1, w, afshari));
        graph[v-1].push_back(edge(u-1, w, afshari));
    }
    order.reserve(V);
    for(int i = 0; i < V; i++){
        naderShah(i);
        if(kahn()){
            for(int x: order)
                printf("%d ", x+1);
            return 0;
        }
    }
    printf("Wrong Map!");
}