#include <bits/stdc++.h>
using namespace std;

struct settings{
    int o1, c1, ob1, ob2, g1, g2;
};

struct states{
    int o, c, ob, g, ro, rc, rob, rg, e;
    states(int o, int c, int ob, int g, int ro, int rc, int rob, int rg, int e){
        this->o = o;
        this->c = c;
        this->ob = ob;
        this->g = g;
        this->ro = ro;
        this->rc = rc;
        this->rob = rob;
        this->rg = rg;
        this->e = e;
    }
    bool operator>(const states& o){
        return this->g > o.g;
    }
};

int solve(settings* setting){
    priority_queue<states*> pq;
    pq.push(new states(0, 0, 0, 0, 1, 0, 0, 0, 24));
    int best = 0;
    while(!pq.empty()){
        states* state = pq.top();
        pq.pop();
        if(state->e == 0){
            best = max(best, state->g);
            continue;
        }
        int potential = 0;
        for(int i = 0; i < state->e; i++){
            potential += i + state->rg;
        }
        if(state->g + potential <= best){
            continue;
        }
        pq.push(
            new states(
                state->o + state->ro,
                state->c + state->rc,
                state->ob + state->rob,
                state->g + state->rg,
                state->ro,
                state->rc,
                state->rob,
                state->rg,
                state->e - 1
            )
        );
        if(state->o >= setting->o1){
            pq.push(
                new states(
                    state->o + state->ro - setting->o1,
                    state->c + state->rc,
                    state->ob + state->rob,
                    state->g + state->rg,
                    state->ro + 1,
                    state->rc,
                    state->rob,
                    state->rg,
                    state->e - 1
                )
            );
        }
        if(state->o >= setting->c1){
            pq.push( 
                new states(
                    state->o + state->ro - setting->c1,
                    state->c + state->rc,
                    state->ob + state->rob,
                    state->g + state->rg,
                    state->ro,
                    state->rc + 1,
                    state->rob,
                    state->rg,
                    state->e - 1
                )
            );
        }
        if(state->o >= setting->ob1 && state->c >= setting->ob2){
            pq.push(
                new states(
                    state->o + state->ro - setting->ob1,
                    state->c + state->rc - setting->ob2,
                    state->ob + state->rob,
                    state->g + state->rg,
                    state->ro,
                    state->rc,
                    state->rob + 1,
                    state->rg,
                    state->e - 1
                )
            );
        }
        if(state->o >= setting->g1 && state->ob >= setting->g2){
            pq.push(
                new states(
                    state->o + state->ro - setting->g1,
                    state->c + state->rc,
                    state->ob + state->rob - setting->g2,
                    state->g + state->rg,
                    state->ro,
                    state->rc,
                    state->rob,
                    state->rg + 1,
                    state->e - 1
                )
            );
        }
    }
    return best;
}

int main() {
    int ans = 0;
    string dummy;
    int index = 0;
    while(cin >> dummy >> dummy){
        index++;
        settings* setting = new settings();
        cin >> dummy >> dummy >> dummy >> dummy >> setting->o1 >> dummy;
        cin >> dummy >> dummy >> dummy >> dummy >> setting->c1 >> dummy;
        cin >> dummy >> dummy >> dummy >> dummy >> setting->ob1 >> dummy >> dummy >> setting->ob2 >> dummy;
        cin >> dummy >> dummy >> dummy >> dummy >> setting->g1 >> dummy >> dummy >> setting->g2 >> dummy;
        ans += index * solve(setting);
    }
    cout << ans << endl;
}