#include <bits/stdc++.h>
using namespace std;

// Pieces of Parentheses

pair<int, int> interpret(string s){
    int op = 0, cl = 0;
    for(char c : s){
        if(c == '(')
            op++;
        else if(c == ')'){
            if(op) op--;
            else cl++;
        }
    }
    return {op, cl};
}

struct pack{
    int op, cl, s;
};

bool cmp(const pack& p1, const pack& p2){
    return p1.cl < p2.cl;
}

int n, ptr;
string str;
pair<int, int> inte;
pack p;
vector<pack> a, b, c;
pack items[303];

int dp[303][180003];

int cdp(int i, int s){
    if(dp[i][s+90000] != -1)
        return dp[i][s+90000];
    if(i == n)
        return dp[i][s+90000] = s ? -2 : 0;
    int ans = cdp(i+1, s);
    int op = max(0, s), cl = max(0, -s);
    if(items[i].cl <= op){
        int subp = cdp(i+1, op + items[i].op - cl - items[i].cl);
        if(subp != -2)
            ans = max(ans, items[i].s + subp);
    }
    return dp[i][s+90000] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        inte = interpret(str);
        p.op = inte.first, p.cl = inte.second, p.s = str.size();
        if(!p.cl)
            a.push_back(p);
        else if(!p.op)
            c.push_back(p);
        else b.push_back(p);
    }
    sort(b.begin(), b.end(), cmp);
    ptr = 0;
    for(pack item : a)
        items[ptr++] = item;
    for(pack item : b)
        items[ptr++] = item;
    for(pack item : c)
        items[ptr++] = item;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 180003; j++)
            dp[i][j] = -1;
    cout << cdp(0, 0) << endl;
}