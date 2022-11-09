#include <bits/stdc++.h>
using namespace std;

// Ingredients

#define num long long int

const int MAXB = 10003;
const int MAXN = 1000003;
pair<num, num> pending = make_pair(-1, -1);
pair<num, num> stop = make_pair(0, 0);

int B, N, cost[MAXN], pres[MAXN];
string name[MAXN], parent[MAXN], dummy;
map<string, int> ids;
vector<int> recipes[MAXB];
pair<num, num> dp[MAXB];

pair<num, num> cdp(const string& dish) {
    auto it = ids.find(dish);
    if (it == ids.end()) {
        return stop;
    }
    int id = it->second;
    if (dp[id] != pending) {
        return dp[id];
    }
    num minCost = LLONG_MAX, maxPres;
    for(int recipe: recipes[id]) {
        pair<num, num> subP = cdp(parent[recipe]);
        num subC = subP.first + cost[recipe];
        num subPr = subP.second + pres[recipe];
        if (subC < minCost) {
            minCost = subC;
            maxPres = subPr;
        }
        else if (subC == minCost && subPr > maxPres) {
            maxPres = subPr;
        }
    }
    return dp[id] = make_pair(minCost, maxPres);
}

num w[MAXB], p[MAXB], k[MAXB];

int main() {
    cin >> B >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> name[i] >> parent[i] >> dummy >> cost[i] >> pres[i];
        auto id = ids.find(name[i]);
        if (id == ids.end()) {
            recipes[cnt].push_back(i);
            ids[name[i]] = cnt++;
        } else {
            recipes[id->second].push_back(i);
        }
    }
    for (int i = 0; i < cnt; i++) {
        dp[i] = pending;
    }
    for (auto it: ids) {
        auto result = cdp(it.first);
        w[it.second] = result.first;
        p[it.second] = result.second;
    }
    k[0] = 0;
    for(int b = 1; b <= B; b++) {
        k[b] = -1;
    }
    for(int i = 0; i < cnt; i++) {
        for(int b = B; b >= 1; b--) {
            if (b >= w[i] && k[b - w[i]] != -1) {
                k[b] = max(k[b], k[b - w[i]] + p[i]);
            }
        }
    }
    num ans = 0, ans_b = 0;
    for (int b = 1; b <= B; b++) {
        if (k[b] > ans) {
            ans = k[b];
            ans_b = b;
        }
    }
    cout << ans << endl;
    cout << ans_b << endl;
}