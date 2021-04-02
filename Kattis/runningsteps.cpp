#include <bits/stdc++.h>
using namespace std;

// Running Steps

long long int dp[53][53][53][53][3];
long long int memo[53];

int main(){
    for(int o1 = 0; o1 <= 50; o1++)
        for(int t1 = 0; t1 <= 50; t1++)
            for(int o2 = 0; o2 <= 50; o2++)
                for(int t2 = 0; t2 <= 50; t2++)
                    for(int turn = 0; turn <= 1; turn++){
                        if(!(o1 + t1 + o2 + t2))
                            dp[o1][t1][o2][t2][turn] = 1;
                        else if(turn){
                            if(o1)
                                dp[o1][t1][o2][t2][turn] += dp[o1-1][t1][o2][t2][!turn];
                            if(t1)
                                dp[o1][t1][o2][t2][turn] += dp[o1][t1-1][o2][t2][!turn];
                        }
                        else{
                            if(o2)
                                dp[o1][t1][o2][t2][turn] += dp[o1][t1][o2-1][t2][!turn];
                            if(t2)
                                dp[o1][t1][o2][t2][turn] += dp[o1][t1][o2][t2-1][!turn];
                        }
                    }
    for(int s = 1; s <= 50; s++){
        for(int o = 0; o <= s; o++)
            if(!((s - o) % 2)){
                int t = (s - o) / 2;
                if(t >= o)
                    memo[s] += dp[o][t][o][t][0];
            }
    }
    int q, k, s;
    cin >> q;
    while(q--)
        cin >> k >> s, cout << k << " " << memo[s/2] << endl;
}