#include <bits/stdc++.h>
using namespace std;

// Shoot-out

int n;
double p[13+3];
valarray<double> memo[(1<<13)+3][13+3][13+3];

valarray<double> dp(int cowboys, int turn, int free){
    if(memo[cowboys][turn][free].size() != 0)
        return memo[cowboys][turn][free];
    valarray<double>& state = memo[cowboys][turn][free];
    state.resize(n, 0.0);
    while(!(cowboys & (1 << (n-1-turn))))
        turn = (turn + 1) % n;
    if(turn == free)
        return state;
    if(cowboys == (1 << (n-1-turn))){
        state[turn] = 1.0;
        return state;
    }
    double denominator = 1.0;
    if(free == 15 && p[turn] != 1.0) 
        for(int i = 0; i < n; i++)
            if(cowboys & (1 << (n-1-i)))
                denominator *= (1.0 - p[i]);
    double best = INT_MIN;
    int ways = 1;
    for(int i = 0; i < n; i++)
        if(i != turn && (cowboys & ( 1 << (n-1-i)))){
            valarray<double> subp = p[turn] * dp(cowboys - (1 << (n-1-i)), (turn+1)%n, 15);
            if(p[turn] != 1.0)
                subp += (1.0 - p[turn]) * dp(cowboys, (turn+1)%n, free == 15 ? turn : free);
            if(free == 15 && p[turn] != 1.0)
                subp /= (1.0 - denominator);
            if(subp[turn] > best + 0.000000001){
                state = subp;
                ways = 1;
            }
            else if(fabs(subp[turn] - best) <= 0.000000001){
                state += subp;
                ways++;
            }
            best = max(best, subp[turn]);
        }
    state /= double(ways);
    return state;
} 

int main(){
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> p[i], p[i] /= 100;
        for(int i = 0; i < (1<<13)+3; i++)
            for(int j = 0; j < 16; j++)
                for(int k = 0; k < 16; k++)
                    memo[i][j][k].resize(0);
        valarray<double> ans = dp((1<<n)-1, 0, 15);
        for(double a : ans)
             cout << a * 100 << " ";
        cout << endl;
    }
}