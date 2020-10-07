#include <bits/stdc++.h>
using namespace std;

// Game Show Math

int n;
int seq[103];

map<pair<int, int>, bool> memo;
map<pair<int, int>, char> trace;

bool cdp(int i, int target){
    if(target >= 32000 || target <= -32000)
        return false;
    pair<int, int> p = {i, target};
    if(memo.find(p) != memo.end())
        return memo[p];
    if(i == 0){
        trace[p] = 'E';
        return memo[p] = target == seq[0];
    }
    bool with_plus = cdp(i-1, target-seq[i]);
    if(with_plus){
        trace[p] = '+';
        return memo[p] = true;
    }
    bool with_minus = cdp(i-1, target+seq[i]);
    if(with_minus){
        trace[p] = '-';
        return memo[p] = true;
    }
    bool with_slash = cdp(i-1, target*seq[i]);
    if(with_slash){
        trace[p] = '/';
        return memo[p] = true;
    }
    if(target % seq[i] == 0){
        bool with_star = cdp(i-1, target/seq[i]);
        if(with_star){
            trace[p] = '*';
            return memo[p] = true;
        }
    }
    return memo[p] = false;
}

vector<char> expr;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> seq[i];
        int target;
        cin >> target;
        memo.clear();
        trace.clear();
        if(cdp(n-1, target)){
            int it_i = n-1;
            int it_target = target;
            expr.clear();
            char it = trace[{it_i, it_target}];
            while(it != 'E'){
                expr.push_back(it);
                if(it == '+')
                    it_target -= seq[it_i];
                if(it == '-')
                    it_target += seq[it_i];
                if(it == '*')
                    it_target /= seq[it_i];
                if(it == '/')
                    it_target *= seq[it_i];
                it_i--;
                it = trace[{it_i, it_target}];
            }
            reverse(expr.begin(), expr.end());
            cout << seq[0];
            for(int i = 1; i < n; i++)
                cout << expr[i-1] << seq[i];
            cout << "=" << target << endl;
        }else{
            cout << "NO EXPRESSION" << endl;
        }

    }
}