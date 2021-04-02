#include <bits/stdc++.h>
using namespace std;

// Bio Trip

#define inf INT_MAX

struct state{
    int node, a;
    bool box;

    bool operator<(const state & o) const{
        return this->a < o.a;
    }
};

int n, d, a1, a2;
vector<int> adjs[1003];
priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>> pq;
int dis[1003][363][2 + 3];

int tw[1003][1003], alpha[1003][1003];

int main(){
    cin >> n >> d >> a1 >> a2;
    d--;
    int x, v;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(x--){
            cin >> v >> tw[i][v-1] >> alpha[i][v-1];
            adjs[i].push_back(v - 1);
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 360; j++)
            for(int k = 0; k < 2; k++)
                dis[i][j][k] = inf;
    for(int i = 0; i < 360; i++){
        state st;
        st.a = i, st.box = (d == 0), st.node = 0;
        dis[0][i][(d == 0)] = 0, pq.push({0, st}); 
    }
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        state st = p.second;
        if(dis[st.node][st.a][st.box] < w)
            continue;
        for(int v : adjs[st.node]){
            int t = tw[st.node][v], deg = alpha[st.node][v];
            int at1 = (deg - st.a + 360) % 360, at2 = 360 - at1;
            if(at1 <= a1 || at2 <= a2){
                int deg2 = (alpha[v][st.node] + 180) % 360;
                if(dis[v][deg2][((v == d) || st.box)] > w + t){
                    state st2;
                    st2.a = deg2, st2.box = ((v == d) || st.box), st2.node = v;
                    dis[v][deg2][((v == d) || st.box)] = w + t, pq.push({w + t, st2});
                }
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < 360; i++)
        ans = min(ans, dis[0][i][1]);
    if(ans != inf)
        cout << ans << endl << endl;
    else
        cout << "impossible" << endl << endl;
}