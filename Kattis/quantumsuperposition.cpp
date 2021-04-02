#include <bits/stdc++.h>
using namespace std;

// Quantum Superposition

int n1, n2, m1, m2, q, p;
vector<int> adj1[1003], adj2[1003];
bool dp1[1003][2003], dp2[1003][2003];

int main(){
    int u, v;
    cin >> n1 >> n2 >> m1 >> m2;
    while(m1--)
        cin >> u >> v, adj1[u-1].push_back(v-1);
    while(m2--)
        cin >> u >> v, adj2[u-1].push_back(v-1);
    for(int j = 0; j < 2001; j++)
        for(int i = 0; i < n1; i++){
            if(j){
                dp1[i][j] = false;
                for(int k : adj1[i])
                    if(dp1[k][j-1]){
                        dp1[i][j] = true;
                        break;
                    }
            }
            else
                dp1[i][j] = i == n1-1;
        }
    for(int j = 0; j < 2001; j++)
        for(int i = 0; i < n2; i++){
            if(j){
                dp2[i][j] = false;
                for(int k : adj2[i])
                    if(dp2[k][j-1]){
                        dp2[i][j] = true;
                        break;
                    }
            }
            else
                dp2[i][j] = i == n2-1;
        }
    cin >> q;
    while(q--){
        cin >> p;
        bool ans = false;
        for(int k = 0; k <= p; k++)
            if(dp1[0][k] && dp2[0][p-k]){
                ans = true;
                break;
            }
        cout << (ans ? "Yes" : "No") << endl;
    }    
}